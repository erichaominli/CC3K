#include "orc.h"

Orc::Orc() : Enemy( 180, 180, 30, 30, 25, 25, 0, "Orc", 'O' ) {}
Orc::~Orc() {}

void Orc::attack( Shade &p )
{
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " O deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " O Attack missed! PC.";
  }
}

void Orc::attack( Drow &p )
{
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " O deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " O Attack missed! PC.";
  }
}

void Orc::attack( Vampire &p )
{
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " O deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " O Attack missed! PC.";
  }
}

void Orc::attack( Troll &p )
{
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " O deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " O Attack missed! PC.";
  }
}

void Orc::attack( Goblin &p )
{
  if ( fiftyFifty() )
  {
    int dmg = damage( p ) * 1.5;
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " O deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " O Attack missed! PC.";
  }
}

void Orc::attackedBy( Player &p ) 
{
  p.attack( *this );
  p.attackedBy( *this );
}
