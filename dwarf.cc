#include "dwarf.h"

Dwarf::Dwarf() : Enemy( 100, 100, 20, 20, 30, 30, 0, "Dwarf", 'W' ) {}
Dwarf::~Dwarf() {}

void Dwarf::attack( Shade &p )
{
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " W deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " W Attack missed! PC.";
  }
}


void Dwarf::attack( Drow &p )
{
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " W deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " W Attack missed! PC.";
  }
}


void Dwarf::attack( Vampire &p )
{
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " W deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " W Attack missed! PC.";
  }
}

void Dwarf::attack( Troll &p )
{
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " W deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " W Attack missed! PC.";
  }
}


void Dwarf::attack( Goblin &p )
{
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " W deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " W Attack missed! PC.";
  }
}


void Dwarf::attackedBy( Player &p )
{
  p.attack( *this );
  p.attackedBy( *this );
} 
