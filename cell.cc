#include <utility>
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"

void Cell::attachNbor( Cell* cell ) { nbors.emplace_back( cell );  }

std::vector<Cell*>* Cell::getNbors() { return &nbors; }

void Cell::notifyNbors()
{
  for ( auto it = nbors.begin(); it != nbors.end(); ++it ) (*it)->notify( *this );
}

Cell::Cell( char sym, int r, int c) : cp{nullptr}, row{r}, col{c} 
{
	if ( sym == 'A' || sym == 'B' || sym == 'C' || sym == 'D' || sym == 'E' )
	{
		symbol = '.';
		name = "tile";
		pmov = true;
		emov = true;
		stair = false;
                pot = false; 
		tre = false; 
		dh = false;
	}
	else if ( sym == '.' ) 
	{
		symbol = '.';
                name = "tile";
                pmov = true;
                emov = true;
                stair = false;
                pot = false;
                tre = false;
                dh = false;
	}
	else if ( sym == '@' )
	{
		symbol = '.';
		name = "tile";
		pmov = true;
		emov = false;
		stair = false;
		pot = false;
		tre = false;
		dh = false;
	}
	else if ( sym == 'H' || sym == 'W' || sym == 'E' || sym == 'O' || sym == 'M' || sym == 'D' || sym == 'L' )
	{
		symbol = '.';
                name = "tile";
                pmov = false;
                emov = false;
                stair = false;
                pot = false;
                tre = false;
                dh = false;
	}
	else if ( sym == 'P' )
	{
		symbol = '.';
                name = "tile";
                pmov = true;
                emov = false;
                stair = false;
                pot = true;
                tre = false;
                dh = false;
	}
	else if ( sym == 'G' )
	{
		symbol = '.';
                name = "tile";
                pmov = true;
                emov = false;
                stair = false;
                pot = false;
                tre = false;
                dh = false;
	}	
	else {
		symbol = sym;
		if ( sym == '#' )
		{
			name = "passage";
			pmov = true;
			emov = false;
			stair = false;
			pot = false;
			tre = false;
			dh = false;
		}
		else if ( sym == '|' )
		{
			name = "Vwall";
			pmov = false;
			emov = false;
			stair = false;
			pot = false;
			tre = false;
			dh = false;
		}
		else if ( sym == '-' )
		{
			name = "Hwall";
			pmov = false;
			emov = false;
			stair = false;
			pot = false;
			tre = false;
			dh = false;
		}
		else if ( sym == ' ' )
		{
			name = "blank";
			pmov = false;
			emov = false;
			stair = false;
			pot = false;
			tre = false;
			dh = false;
		}
		else if ( sym == '\n' )
		{
			name = "newline";
			pmov = false;
			emov = false;
			stair = false;
			pot = false;
			tre = false;
			dh = false;
		}
		else if ( sym == '\\' )
		{
			name = "stairs";
			pmov = true;
			emov = false;
			stair = true;
			pot = false;
			tre = false;
			dh = false;
		}       
		else if ( sym == '+' )
		{
			name = "exit";
			pmov = true;
			emov = false;
			stair = false;
			pot = false;
			tre = false;
			dh = false;
		}
	}
}

Cell::~Cell() { delete cp; }

void Cell::link( Cell* nbor )
{
   attachNbor( nbor );
   nbor->attachNbor( this );
}

Character* Cell::getCp() const { return cp; }
char Cell::getSymbol() const { return symbol; }
std::string Cell::getname() const { return name; }
int Cell::getRow() const { return row; }
int Cell::getCol() const { return col; }
bool Cell::getEmov() const { return emov; }
bool Cell::getPmov() const { return pmov; }
bool Cell::getStair() const {return stair; }
bool Cell::getPot() const { return pot; }
bool Cell::getTre() const { return tre; }
bool Cell::getDh() const { return dh;}
std::string Cell::getTreasure() const { return name; }
void Cell::unSet() {
 
     if ( cp->getType() == "enemy" ) { 
     emov = true;
     pmov = true;
     pot = false;
     tre = false;
     stair = false;
  }
  else  pmov = true;
  cp = nullptr;
}


void Cell::set( Character* cp1 ) 
{ 
    cp = cp1;
    emov = false;
    pmov = false;
    cp->mutRow( row );
    cp->mutCol( col );
}

void Cell::notify( Cell &whoNotified )
{
	if ( whoNotified.cp->getType() == "player" ) { 
		if ( cp && cp->getRace() != "Dragon" )  
		{
			int hp = whoNotified.cp->getHP();
			std::string symb;
			std::stringstream ss;
                        ss << cp->getSymbol();
			ss >> symb;
			static_cast<Player*>(whoNotified.cp)->attackedBy( *static_cast<Enemy*>(cp) ); 
			if ( hp == whoNotified.cp->getHP() )
                        {
				if ( cp->getRace() == "Merchant" && !Merchant::agro ) return;
				whoNotified.cp->addToAct(" " + symb + " attack missed!");
                        	return;
                        }
                        double a = cp->getAtk();
                        double b = whoNotified.cp->getDef();
                        int dmg = ceil( ( 100 / ( 100 + b )  ) * a );
                        std::string sdmg = std::to_string(dmg);
                        whoNotified.cp->addToAct(" and " + symb + " deals " + sdmg + " to PC." );
                        return;	
		}
		else if ( pot ) whoNotified.cp->addToAct( " and sees an unkown potion.");
		if ( whoNotified.getDh() ) whoNotified.getCp()->clearAct();
		if ( dh || whoNotified.getDh() ) 
		{
			if ( dh ) whoNotified.getCp()->clearAct();
			for ( auto it = nbors.begin(); it != nbors.end(); ++it )
			{
				if ( (*it)->cp && (*it)->cp->getRace() == "Dragon"  ){ 
					int hp = whoNotified.cp->getHP();
					static_cast<Player*>(whoNotified.cp)->attackedBy(*static_cast<Enemy*>((*it)->cp) );
					whoNotified.cp->addToAct(" and is near a DH.");
					if ( hp == whoNotified.cp->getHP() )
					{ 
						whoNotified.cp->addToAct(" D attack missed!");
						return;
					}
					double a = (*it)->cp->getAtk();
					double b = whoNotified.cp->getDef();
 					int dmg = ceil( ( 100 / ( 100 + b )  ) * a );
					std::string sdmg = std::to_string(dmg);
  					whoNotified.cp->addToAct(" D deals " + sdmg + " to PC." );
					return;
				}
			}	
		}
	}
}

void Cell::setStair()
{
  cp = nullptr;
  symbol = '\\';
  stair = true;
  name = "stair";
  emov = false;
  pmov = true;
  dh = false;
}

void Cell::setPotion()
{
  cp = nullptr;
  symbol = 'P';
  pot = true;
  stair = false;
  name = "potion";
  emov = false;
  pmov = true;
  dh = false;
}

void Cell::removePotion()
{
  symbol = '.';
  pot = false;
  emov = true;
  pmov = true;
  name = "tile";
  dh = false;
}

void Cell::setTreasure( std::string ttype )
{
  cp = nullptr;
  symbol = 'G';
  name = ttype;
  if ( ttype == "dragon" ) 
  {
    tre = false;
    dh = true;
  }
  else 
  {
    tre = true;
    dh = false;
  }
  pot = false;
  emov = false;
  pmov = true;
}

void Cell::removeTreasure()
{
  symbol = '.';
  emov = true;
  tre = false;
  dh = false;
  name = "tile";
}

void Cell::unSetDh()
{
  for ( auto it = nbors.begin(); it != nbors.end(); ++it )
    {
      if ( (*it)->dh )
      {
        (*it)->dh = false;
        (*it)->tre = true;
        break;
      }
    }
}
