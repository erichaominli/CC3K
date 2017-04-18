#include "human.h"

Human::Human() : Enemy( 140, 140, 20, 20, 20, 20, 0, "Human", 'H' ) {}
Human::~Human(){}

void Human::attack( Shade &p )
{
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " H deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    std::string hp = std::to_string(p.getHP() );
    act = " H Attack missed! PC.";
  }
}

	 
void Human::attack( Drow &p )
{
  if ( fiftyFifty() )
  { 
    int dmg = damage( p );
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " H deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    std::string hp = std::to_string(p.getHP() );
    act = " H Attack missed! PC.";
  }
}

void Human::attack( Vampire &p )
{
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
      act = "";
    std::string sdmg = std::to_string(dmg);
    act = " H deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " H Attack missed! PC.";
  }

}

void Human::attack( Troll &p )
{
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    p.mutHP( -dmg );
      act = "";
    std::string sdmg = std::to_string(dmg);
    act = " H deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " H Attack missed! PC.";
  }

}


void Human::attack( Goblin &p )
{
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " H deals " + sdmg + " to PC.";
  }
  else
  {
    act = "";
    act = " H Attack missed! PC.";
  }
}


void Human::attackedBy( Player &p ) 
{ 
  p.attack( *this );  
  p.attackedBy( *this );
}
