#include "halfling.h"

Halfling::Halfling() : Enemy( 100, 100, 15, 15, 20, 20, 0, "Halfling", 'L' ) {}
Halfling::~Halfling() {}

void Halfling::attack( Shade &p )
{
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " L deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " L Attack missed! PC.";
  }
}

void Halfling::attack( Drow &p )
{
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " L deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " L Attack missed! PC.";
  }
}

void Halfling::attack( Vampire &p )
{
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " L deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " L Attack missed! PC.";
  }
}

void Halfling::attack( Troll &p )
{
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " L deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " L Attack missed! PC.";
  }
}

void Halfling::attack( Goblin &p )
{
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " L deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " L Attack missed! PC.";
  }
}

void Halfling::attackedBy( Player &p )
{
  p.attack( *this );
  p.attackedBy( *this );
}
