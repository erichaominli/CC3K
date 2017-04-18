#include "floor.h"
#include "subscriptions.h"
#include "subject.h"
#include "shade.h"
#include "ctime"
#include <stdexcept>
#include "result.h"

Floor::Floor( bool readMap, int level, std::ifstream& file, std::string cmd ) 
: action{" Player character has spawned."}, readMap{readMap}, level{level}, len{len}, wid{wid}, file(file)
{
  if ( cmd == "s" || cmd == "S" ) mainChar = new Shade;
  else if ( cmd == "d" || cmd == "D" ) mainChar = new Drow;
  else if ( cmd == "v" || cmd == "V" ) mainChar = new Vampire;
  else if ( cmd == "g" || cmd == "G" ) mainChar = new Goblin;
  else if ( cmd == "t" || cmd == "T" ) mainChar = new Troll;
}

Player* Floor::getMainChar(){ return mainChar; }

void Floor::clearFloor() 
{ 
  if ( readMap ) file.clear();
  if ( readMap ) file.seekg(0, file.beg);
  theFloor.clear(); 
  theChambers.clear();
  theEnemies.clear();
  theDragons.clear();
}

Floor::~Floor() { clearFloor(); }


void Floor::init( std::ifstream& file ) 
{
	mainChar->setDef( mainChar->getBaseDef() ) ;
	mainChar->setAtk( mainChar->getBaseAtk() ) ;
	if ( theFloor.size() ) clearFloor();

	// make vectorsi
	if ( !readMap )
	{
		for ( int i = 0; i < 5; ++i )
		{
			Chamber* ch = new Chamber;
			theChambers.emplace_back( ch );
		}    
		srand( time(NULL) );
		for ( int i = 0; i < 20; ++i ) 
		{
			int rng = rand() % 18; 
			if ( rng < 4 ) 
			{
				Human* ene = new Human;
				theEnemies.emplace_back( ene );
			}
			else if ( rng < 7 )
			{
				Dwarf* ene = new Dwarf;
				theEnemies.emplace_back( ene );
			}
			else if ( rng < 12 ) 
			{
					Halfling* ene = new Halfling;
				theEnemies.emplace_back( ene );
			}
			else if ( rng < 14 )
			{
				Elf* ene = new Elf;
				theEnemies.emplace_back( ene );
			}
			else if ( rng < 16 )
			{
				Orc* ene = new Orc;
				theEnemies.emplace_back( ene );
			}
			else 
			{
				Merchant* ene = new Merchant;
				theEnemies.emplace_back( ene );
			}
		}
	
		int row = 0;
		int col = 0;
		char cha;
		while ( file.get(cha) ) 
		{
			if (col == 0 ) 
			{
				theFloor.emplace_back();
			}
			if ( col >= 0 && col < 80 )
			{
				Cell *cell = new Cell( cha, row, col ); // leak mem?
				theFloor[row].emplace_back( cell );
				if ( cha == 'A' ) theChambers.at( 0 )->theChamber.emplace_back( cell );
				else if ( cha == 'B' ) theChambers.at( 1 )->theChamber.emplace_back( cell ); 
				else if ( cha == 'C' ) theChambers.at( 2 )->theChamber.emplace_back( cell );
				else if ( cha == 'D' ) theChambers.at( 3 )->theChamber.emplace_back( cell );
				else if ( cha == 'E' ) theChambers.at( 4 )->theChamber.emplace_back( cell ); 
				if ( row != 0 && col != 0 ) 
				{
					cell->link( theFloor[row-1][col] ); // link to the left
					cell->link( theFloor[row-1][col-1] ); // link up left
					cell->link( theFloor[row][col-1] ); // link up
				}
				else if ( row != 0 ) cell->link( theFloor[row-1][col] ); 
				else if ( col != 0 ) cell->link( theFloor[row][col-1] );
				if ( row != 0 && col != 79 ) cell->link( theFloor[row-1][col+1] );
				++col;
			}
			if ( col == 80 )
			{
				col = 0;
				++row;
			}
		}
		srand( time(NULL) );
		int charChamb = rand() % 5;
		theChambers.at( charChamb )->placeChar( mainChar );
		for ( int i = 0; i < 20; ++i )
		{
			int z = rand() % 5;
			theChambers.at( z )->placeChar( theEnemies.at( i ) );
		}
		// place stair not in chamber q
		while ( true )
		{
			int cham = rand() % 5;
			if ( cham != charChamb ) 
			{
				int pos = rand() % (theChambers.at( cham )->theChamber.size());
				theChambers.at( cham )->theChamber.at( pos )->setStair();
				break;
			}
		}
		// place potions;
		srand( time(NULL) );
		for ( int i = 0; i < 10; ++i )
		{
			int cham = rand() % 5;
			int pos = rand() % ( theChambers.at( cham )->theChamber.size() );
			theChambers.at( cham )->theChamber.at( pos )->setPotion();
			theChambers.at( cham )->remove( pos); 
		}
		srand( time(NULL) );
		//place treasures
		for ( int i = 0; i < 10; ++i )
		{
			int cham = rand() % 5;
			int pos = rand() % ( theChambers.at( cham )->theChamber.size() );
			int tr = rand() % 8;
			if ( tr < 2 ) theChambers.at( cham )->theChamber.at( pos )->setTreasure( "small" );
			else if ( tr < 7 ) theChambers.at( cham )->theChamber.at( pos )->setTreasure( "normal" );
			else 
			{ 
				Dragon* dra = new Dragon;
				theChambers.at( cham )->theChamber.at( pos )->setTreasure( "dragon" );
				int dpos;
				srand( time(NULL) );
				while(true)
				{
					int r = theChambers.at( cham )->theChamber.at( pos )->getRow();
					int c = theChambers.at( cham )->theChamber.at( pos )->getCol();
					dpos = rand() % 8;
					if ( dpos == 0 && theFloor[r-1][c-1]->getEmov() ) 
					{ 
						theFloor[r-1][c-1]->set( dra );
						break;
					}
					else if ( dpos == 1 && theFloor[r-1][c]->getEmov() ) 
					{
						theFloor[r-1][c]->set(dra);
						break;
					}
					else if ( dpos == 2 && theFloor[r-1][c+1]->getEmov() ) 
					{
						theFloor[r-1][c+1]->set( dra );
						break;
					}
					else if ( dpos == 3 && theFloor[r][c-1]->getEmov() ) 
					{
						theFloor[r][c-1]->set( dra );
						break;
					}
					else if ( dpos == 4 && theFloor[r][c+1]->getEmov() ) 
					{
						theFloor[r][c+1]->set( dra );
						break;
					}
					else if ( dpos == 5 && theFloor[r+1][c-1]->getEmov() ) 
					{
						theFloor[r+1][c-1]->set( dra );
						break;
					}
					else if ( dpos == 6 && theFloor[r+1][c]->getEmov() ) 
					{
						theFloor[r+1][c]->set( dra );
						break;
					}
					else if ( dpos == 7 && theFloor[r+1][c+1]->getEmov() ) 
					{
						theFloor[r+1][c+1]->set( dra );
						break;
					}
					 
				}
				theChambers.at( cham )->remove( pos ); 
			}
		}
	}
	else if ( readMap )
	{
		int row = 0;
                int col = 0;
                char cha;
                while ( file.get(cha) )
                {
                        if (col == 0 )//edit
                        {
                                theFloor.emplace_back();
                        }
                        if ( col >= 0 && col < 80 )//ediy
                        {
                                Cell *cell = new Cell( cha, row, col );
                                theFloor[row].emplace_back( cell );
				if ( cha == '@') theFloor[row][col]->set( mainChar );
				else if ( cha == 'H' )
				{
					Human *ene = new Human;
					theEnemies.emplace_back( ene );
					theFloor[row][col]->set( ene );
				}
				else if ( cha == 'W' )
				{
                                        Dwarf *ene = new Dwarf;
                                        theEnemies.emplace_back( ene );
                                        theFloor[row][col]->set( ene );
                                }                
				else if ( cha == 'E' )
				{
                                        Elf *ene = new Elf;
                                        theEnemies.emplace_back( ene );
                                        theFloor[row][col]->set( ene );
                                }
				else if ( cha == 'O' )
				{
                                        Orc *ene = new Orc;
                                        theEnemies.emplace_back( ene );
                                        theFloor[row][col]->set( ene );
                                }
				else if ( cha == 'M' )
				{
                                        Merchant *ene = new Merchant;
                                        theEnemies.emplace_back( ene );
                                        theFloor[row][col]->set( ene );
                                }
				else if ( cha == 'D' )
				{
                                        Dragon *ene = new Dragon;
                                        theDragons.emplace_back( ene );
                                        theFloor[row][col]->set( ene );
                                }
				else if ( cha == 'L' )
				{
                                        Halfling *ene = new Halfling;
                                        theEnemies.emplace_back( ene );
                                        theFloor[row][col]->set( ene );
                                }
                                if ( row != 0 && col != 0 )
                                {
                                        cell->link( theFloor[row-1][col] ); // link to the left
                                        cell->link( theFloor[row-1][col-1] ); // link up left
                                        cell->link( theFloor[row][col-1] ); // link up
                                }
                                else if ( row != 0 ) cell->link( theFloor[row-1][col] );
                                else if ( col != 0 ) cell->link( theFloor[row][col-1] );
                                if ( row != 0 && col != 79 ) cell->link( theFloor[row-1][col+1] );
                                ++col;
                        }
                        if ( col == 80 )
                        {
                                col = 0;
                                ++row;
                        }
                }
	}
}

void Floor::moveEnemies()
{
  int len = theEnemies.size();
  std::cout << "Enemy size " << len << std::endl;
  srand( time(NULL) );
  std::string randPos[8] = {"no", "ea", "we", "so", "nw", "ne", "se", "sw"};
  for ( int i = 0; i < len; ++i )
  {
    bool mov = true;
    int er = theEnemies[i]->getRow();
    int ec = theEnemies[i]->getCol();
    int pr = mainChar->getRow();
    int pc = mainChar->getCol();
    if ( er == pr && ec == pc - 1  ) mov = false;
    else if ( er == pr && ec == pc + 1  ) mov = false;
    else if ( er == pr + 1 && ec == pc - 1 ) mov = false;
    else if ( er == pr + 1 && ec == pc + 1 ) mov = false;
    else if ( er == pr + 1 && ec == pc ) mov = false;
    else if ( er == pr - 1 && ec == pc - 1 ) mov = false;
    else if ( er == pr - 1 && ec == pc + 1 ) mov = false;
    else if ( er == pr - 1 && ec == pc ) mov = false;
    if ( mov )
    {
      int rng = rand() % 8;
      move( theEnemies[i], randPos[rng]);
    }
  }
}

void Floor::move( Character* cp1, std::string direction )
{
  int startRow = cp1->getRow();
  int startCol = cp1->getCol();
  if ( direction == "no" )
  {
    if (cp1->getType() == "player"? theFloor[startRow-1][startCol]->getPmov() : theFloor[startRow-1][startCol]->getEmov()) 
    { 
      if (cp1->getType() == "player")  action = action +  " PC moves North";
      theFloor[startRow-1][startCol]->set( theFloor[startRow][startCol]->getCp() );
      cp1->mutRow(startRow-1);
      theFloor[startRow][startCol]->unSet();
      theFloor[startRow-1][startCol]->notifyNbors();
    }
  }
  else if ( direction == "nw" )
  {
    if (cp1->getType() == "player"?  theFloor[startRow-1][startCol-1]->getPmov() :  theFloor[startRow-1][startCol-1]->getEmov()) 
    {  
       if (cp1->getType() == "player") action = action +  " PC moves NorthWest";
       theFloor[startRow-1][startCol-1]->set( theFloor[startRow][startCol]->getCp() );
       cp1->mutRow(startRow-1);
       cp1->mutCol(startCol-1);
       theFloor[startRow][startCol]->unSet();
       theFloor[startRow-1][startCol-1]->notifyNbors();
    }
  }
  else if ( direction == "ne" )
  {
    if (cp1->getType() == "player"? theFloor[startRow-1][startCol+1]->getPmov() :  theFloor[startRow-1][startCol+1]->getEmov()) 
    {  
      if (cp1->getType() == "player") action = action + " PC moves NorthEast";
      theFloor[startRow-1][startCol+1]->set( theFloor[startRow][startCol]->getCp() );
      cp1->mutRow(startRow-1);
      cp1->mutCol(startCol+1);
      theFloor[startRow][startCol]->unSet();
      theFloor[startRow-1][startCol+1]->notifyNbors();
    }
  }
  else if (direction == "so")
  {
    if (cp1->getType() == "player"?  theFloor[startRow+1][startCol]->getPmov() :  theFloor[startRow+1][startCol]->getEmov()) 
    { 
      if (cp1->getType() == "player") action = action + " PC moves South";
      theFloor[startRow+1][startCol]->set( theFloor[startRow][startCol]->getCp() );
      cp1->mutRow(startRow+1);
      theFloor[startRow][startCol]->unSet();
      theFloor[startRow+1][startCol]->notifyNbors();
    }
  }
  else if (direction == "se")
  {
    if (cp1->getType() == "player"?  theFloor[startRow+1][startCol+1]->getPmov() :  theFloor[startRow+1][startCol+1]->getEmov()) 
    {  
      if (cp1->getType() == "player") action =  action + " PC moves SouthEast";
      theFloor[startRow+1][startCol+1]->set( theFloor[startRow][startCol]->getCp() );
      cp1->mutRow(startRow+1);
      cp1->mutCol(startCol+1);
      theFloor[startRow][startCol]->unSet();
      theFloor[startRow+1][startCol+1]->notifyNbors();
    }
  }
  else if (direction == "sw")
  {
    if (cp1->getType() == "player"?  theFloor[startRow+1][startCol-1]->getPmov() :  theFloor[startRow+1][startCol-1]->getEmov())
    {  
      if (cp1->getType() == "player") action = action + " PC moves SouthWest";
      theFloor[startRow+1][startCol-1]->set( theFloor[startRow][startCol]->getCp() );
      cp1->mutRow(startRow+1);
      cp1->mutCol(startCol-1);
      theFloor[startRow][startCol]->unSet();
      theFloor[startRow+1][startCol-1]->notifyNbors();
    }
  }
  else if (direction == "ea")
  {
    if (cp1->getType() == "player" ?  theFloor[startRow][startCol+1]->getPmov() :  theFloor[startRow][startCol+1]->getEmov()) 
    {  
      if (cp1->getType() == "player") action =  action +" PC moves East";
      theFloor[startRow][startCol+1]->set( theFloor[startRow][startCol]->getCp() );
      cp1->mutCol(startCol+1);
      theFloor[startRow][startCol]->unSet();
      theFloor[startRow][startCol+1]->notifyNbors();
    }
  }
  else if (direction == "we")
  {
    if (cp1->getType() == "player" ?  theFloor[startRow][startCol-1]->getPmov() :  theFloor[startRow][startCol-1]->getEmov()) 
    {  
      if (cp1->getType() == "player") action = action +  " PC moves West";
      theFloor[startRow][startCol-1]->set( theFloor[startRow][startCol]->getCp() );
      cp1->mutCol(startCol-1);
      theFloor[startRow][startCol]->unSet();
      theFloor[startRow][startCol-1]->notifyNbors();
    }
  }
  
  if( isAtStairs() ) std::cout << isWon() << std::endl;
  if ( isAtPotion() ) 
  {
    consumePotion();
    theFloor[cp1->getRow()][cp1->getCol()]->removePotion();
  }
  if ( isAtTreasure() )
  {
    consumeTreasure( theFloor[ mainChar->getRow() ][ mainChar->getCol() ]->getTreasure() ); 
    theFloor[cp1->getRow()][cp1->getCol()]->removeTreasure(); 
  }
  if (cp1->getType() == "player") 
  {
    action = action + cp1->getAct();
    cp1->clearAct();
  }
}

void Floor::attack( std::string direction )
{
//  int currHP = mainChar->getHp();

  if ( direction == "no" )
  {
    if ( theFloor[mainChar->getRow()-1][mainChar->getCol()]->getCp() && theFloor[mainChar->getRow()-1][mainChar->getCol()]->getCp()->getType() == "enemy" )
    {
      static_cast<Enemy*>(theFloor[mainChar->getRow()-1][mainChar->getCol()]->getCp())->attackedBy( *static_cast<Player*>(mainChar) );
      action = mainChar->getAct() + theFloor[mainChar->getRow()-1][mainChar->getCol()]->getCp()->getAct();
      if( theFloor[mainChar->getRow()-1][mainChar->getCol()]->getCp()->getDead() ) slainEnemy(  static_cast<Enemy*>(theFloor[mainChar->getRow()-1][mainChar->getCol()]->getCp() ) );
    }
  }
  else if ( direction == "so" )
  {
    if ( theFloor[mainChar->getRow()+1][mainChar->getCol()]->getCp() && theFloor[mainChar->getRow()+1][mainChar->getCol()]->getCp()->getType() == "enemy" )
    {
      static_cast<Enemy*>(theFloor[mainChar->getRow()+1][mainChar->getCol()]->getCp())->attackedBy( *static_cast<Player*>(mainChar) );
      action = mainChar->getAct() + theFloor[mainChar->getRow()+1][mainChar->getCol()]->getCp()->getAct();
      if( theFloor[mainChar->getRow()+1][mainChar->getCol()]->getCp()->getDead() ) slainEnemy(  static_cast<Enemy*>(theFloor[mainChar->getRow()+1][mainChar->getCol()]->getCp() ));
    }
  }
  else if ( direction == "ea" )
  {
    if ( theFloor[mainChar->getRow()][mainChar->getCol()+1]->getCp() && theFloor[mainChar->getRow()][mainChar->getCol()+1]->getCp()->getType() == "enemy" )
    {
      static_cast<Enemy*>(theFloor[mainChar->getRow()][mainChar->getCol()+1]->getCp())->attackedBy( *static_cast<Player*>(mainChar) );
      action = mainChar->getAct() + theFloor[mainChar->getRow()][mainChar->getCol()+1]->getCp()->getAct();
      if( theFloor[mainChar->getRow()][mainChar->getCol()+1]->getCp()->getDead() ) slainEnemy( static_cast<Enemy*>( theFloor[mainChar->getRow()][mainChar->getCol()+1]->getCp()) );
    }
  }
  else if ( direction == "we" )
  {
    if ( theFloor[mainChar->getRow()][mainChar->getCol()-1]->getCp() && theFloor[mainChar->getRow()][mainChar->getCol()-1]->getCp()->getType() == "enemy" )
    {
      static_cast<Enemy*>(theFloor[mainChar->getRow()][mainChar->getCol()-1]->getCp())->attackedBy( *static_cast<Player*>(mainChar) );
      action = mainChar->getAct() + theFloor[mainChar->getRow()][mainChar->getCol()-1]->getCp()->getAct();
      if( theFloor[mainChar->getRow()][mainChar->getCol()-1]->getCp()->getDead() ) slainEnemy(  static_cast<Enemy*>(theFloor[mainChar->getRow()][mainChar->getCol()-1]->getCp() ));
    }
  }
  else if ( direction == "nw" )
  {
    if ( theFloor[mainChar->getRow()-1][mainChar->getCol()-1]->getCp() && theFloor[mainChar->getRow()-1][mainChar->getCol()-1]->getCp()->getType() == "enemy" )
    {
      static_cast<Enemy*>(theFloor[mainChar->getRow()-1][mainChar->getCol()-1]->getCp())->attackedBy( *static_cast<Player*>(mainChar) );
      action = mainChar->getAct() + theFloor[mainChar->getRow()-1][mainChar->getCol()-1]->getCp()->getAct();
      if( theFloor[mainChar->getRow()-1][mainChar->getCol()-1]->getCp()->getDead() ) slainEnemy( static_cast<Enemy*>( theFloor[mainChar->getRow()-1][mainChar->getCol()-1]->getCp() ));
    }
  }
  else if ( direction == "ne" )
  {
    if ( theFloor[mainChar->getRow()-1][mainChar->getCol()+1]->getCp() && theFloor[mainChar->getRow()-1][mainChar->getCol()+1]->getCp()->getType() == "enemy" )
    {
      static_cast<Enemy*>(theFloor[mainChar->getRow()-1][mainChar->getCol()+1]->getCp())->attackedBy( *static_cast<Player*>(mainChar) );
      action = mainChar->getAct() + theFloor[mainChar->getRow()-1][mainChar->getCol()+1]->getCp()->getAct();
      if( theFloor[mainChar->getRow()-1][mainChar->getCol()+1]->getCp()->getDead() ) slainEnemy(  static_cast<Enemy*>(theFloor[mainChar->getRow()-1][mainChar->getCol()+1]->getCp() ));
    }
  }
  else if ( direction == "se" )
  {
    if ( theFloor[mainChar->getRow()+1][mainChar->getCol()+1]->getCp() && theFloor[mainChar->getRow()+1][mainChar->getCol()+1]->getCp()->getType() == "enemy" )
    {
      static_cast<Enemy*>(theFloor[mainChar->getRow()+1][mainChar->getCol()+1]->getCp())->attackedBy( *static_cast<Player*>(mainChar) );
      action = mainChar->getAct() + theFloor[mainChar->getRow()+1][mainChar->getCol()+1]->getCp()->getAct();
      if( theFloor[mainChar->getRow()+1][mainChar->getCol()+1]->getCp()->getDead() ) slainEnemy( static_cast<Enemy*>( theFloor[mainChar->getRow()+1][mainChar->getCol()+1]->getCp() ));
    }
  }
  else if ( direction == "sw" )
  {
    if ( theFloor[mainChar->getRow()+1][mainChar->getCol()-1]->getCp() && theFloor[mainChar->getRow()+1][mainChar->getCol()-1]->getCp()->getType() == "enemy" )
    {
      static_cast<Enemy*>(theFloor[mainChar->getRow()+1][mainChar->getCol()-1]->getCp())->attackedBy( *static_cast<Player*>(mainChar) );
      action = mainChar->getAct() + theFloor[mainChar->getRow()+1][mainChar->getCol()-1]->getCp()->getAct();
      if( theFloor[mainChar->getRow()+1][mainChar->getCol()-1]->getCp()->getDead() ) slainEnemy(  static_cast<Enemy*>(theFloor[mainChar->getRow()+1][mainChar->getCol()-1]->getCp() ));
    }
  }
}


bool Floor::isAtStairs() { return theFloor[mainChar->getRow()][mainChar->getCol()]->getStair(); }
bool Floor::isAtPotion() { return theFloor[mainChar->getRow()][mainChar->getCol()]->getPot(); }
bool Floor::isAtTreasure() { return theFloor[mainChar->getRow()][mainChar->getCol()]->getTre(); }

void Floor::consumeTreasure( std::string s )
{
  Player * temp2;
  if ( s == "small" ) 
  {
    temp2 = new Small{mainChar};
    action = action + " and picks up ST";
  }
  else if ( s == "normal" ) 
  {
    temp2 = new Normal{mainChar};
    action = action + " and picks up NT";
  }
  else if ( s == "dragon" )
  {  
    temp2 = new DragonHoard{mainChar};
    action = action + " and picks up DH";
  }
  else if ( s == "merchant" ) 
  {
    temp2 = new MerchantHoard{mainChar};
    action = action + " and picks up MH";
  }
  mainChar->setGold( temp2->getGold() );
  delete temp2;
}



void Floor::consumePotion()
{ 
  srand( time(NULL) );
  int rng = rand() % 6; 
  //make temp copy of main char on heap
  Player * temp2;
  if ( rng == 0 )  
  {
    temp2= new BoostAtk{mainChar};
    action = action + " uses BA";
  }
  else if ( rng == 1 ) 
  {
    temp2 = new BoostDef{mainChar};
    action = action + " uses BD";
  }
  else if ( rng == 2 ) 
  {
    temp2 = new WoundAtk{mainChar};
    action = action + " uses WA";
  }
  else if ( rng == 3 ) 
  {
  temp2 = new WoundDef{mainChar};
  action = action + " uses WD";
  }
  else if ( rng == 4 ) 
  {
    temp2  = new RestoreHealth{mainChar};
    action = action + " uses RH";
  }
  else 
  {
    temp2 = new PoisonHealth{mainChar};
    action = action + " uses PH";
  }
  if ( temp2->getHP() <= 0 )
  {
    return;
  }

  mainChar->setHP( temp2->getHP() );
  mainChar->setDef( temp2->getDef() );
  mainChar->setAtk( temp2->getAtk() );
  delete temp2;
}


std::string Floor::isWon()
{
	if ( level == 5 ){ 
             throw result{"Win"};
             return "WIN!";
}
	else 
	{ 
		++level;
		file.clear();
		file.seekg(0, file.beg);
		init( file );
		return "New Floor!";
	}
}

void Floor::slainEnemy( Enemy* e )
{
  if ( e->getRace() == "Human" )
  {
    if ( mainChar-> getRace() == "Goblin" && !mainChar->getDead() ) mainChar->mutGold(5);
    else 
    {
      theFloor[e->getRow()][e->getCol()]->unSet();
      theFloor[e->getRow()][e->getCol()]->setTreasure( "merchant" );  
    }
  }
  else if ( e->getRace() == "Merchant" )
  {
    if (mainChar-> getRace() == "Goblin" && !mainChar->getDead() ) mainChar->mutGold(5);
    else
    {
      theFloor[e->getRow()][e->getCol()]->unSet();
      theFloor[e->getRow()][e->getCol()]->setTreasure( "merchant" );  
    }
  }
  else if ( e->getRace() == "Dragon" )
  {
    if (mainChar-> getRace() == "Goblin" && !mainChar->getDead() ) mainChar->mutGold(5);
    else
    {
    theFloor[e->getRow()][e->getCol()]->unSetDh();
    theFloor[e->getRow()][e->getCol()]->unSet();
    }
  }
  else 
  {
    if (mainChar-> getRace() == "Goblin" && !mainChar->getDead() ) mainChar->mutGold(5);
    else
    {
      srand( time(NULL));
      mainChar->mutGold( rand() % 1 + 1 );
      theFloor[e->getRow()][e->getCol()]->unSet();
    }
  }
}

void Floor::clearAction() { action = ""; }

std::ostream &operator<<(std::ostream &out, const Floor &f) 
{
  for(int row = 0; row < 25; row++)
  {
    for(int col = 0; col < 80; col++) 
    {
      if ( f.theFloor[row][col]->getCp() ) { out << f.theFloor[row][col]->getCp()->getSymbol(); }
      else out << f.theFloor[row][col]->getSymbol();
    }
  }
  out << "Race: "<< f.mainChar->getRace() << " Gold: " << f.mainChar->getGold();
  out << "						Floor " << f.level << std::endl;
  out << "HP: " << f.mainChar->getHP() << std::endl;
  out << "Atk: " << f.mainChar->getAtk() << std::endl;
  out << "Def: " << f.mainChar->getDef() << std::endl;
  out << "Action:" << f.action << std::endl; 
  return out;
	}

