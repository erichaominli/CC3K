#include "dragon.h"

Dragon::Dragon() : Enemy( 150, 150, 20, 20, 20, 20, 0, "Dragon", 'D' ) {}
Dragon::~Dragon() {}

void Dragon::attack( Shade &p )
{
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " D deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " D Attack missed! PC.";
  }
}

void::Dragon::attack( Troll &p )
{
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " D deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " D Attack missed! PC.";
  }
}

void Dragon::attack( Drow &p )
{
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " D deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " D Attack missed! PC.";
  }
}

void Dragon::attack( Vampire &p )
{
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " D deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " D Attack missed! PC.";
  }
}

void Dragon::attack( Goblin &p )
{
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " D deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " D Attack missed! PC.";
  }
}

void Dragon::attackedBy( Player &p )
{
  p.attack( *this );
  p.attackedBy( *this );
}
