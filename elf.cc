#include "elf.h"

Elf::Elf() : Enemy( 140, 140, 30, 30, 10, 10, 0, "Elf", 'E' ) {}
Elf::~Elf() {}

void Elf::attack( Shade &p )
{
  int dmg = damage( p );
  if ( fiftyFifty() )
  {
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " E deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " E Attack missed! PC.";
  }

  if ( p.getHP() <= 0 ) return;
  
  if ( fiftyFifty() )
  {
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " E deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " E Attack missed! PC.";
  }
}

void Elf::attack( Drow &p )
{
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " E deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " E Attack missed! PC.";
  }
}


void Elf::attack( Vampire &p )
{
  int dmg = damage( p );
  if ( fiftyFifty() )
  {
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " E deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " E Attack missed! PC.";
  }

  if ( p.getHP() <= 0 ) return;
  
  if ( fiftyFifty() )
  { 
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " E deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " E Attack missed! PC.";
  }
}

void Elf::attack( Troll &p )
{
  int dmg = damage( p );
  if ( fiftyFifty() )
  {
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " E deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " E Attack missed! PC.";
  }

  if ( p.getHP() <= 0 ) return;
  
  if ( fiftyFifty() )
  { 
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " E deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " E Attack missed! PC.";
  }
}

void Elf::attack( Goblin &p )
{
  int dmg = damage( p );
  if ( fiftyFifty() )
  {
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " E deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " E Attack missed! PC.";
  }

  if ( p.getHP() <= 0 ) return;
  
  if ( fiftyFifty() )
  { 
    int dmg = damage( p );
    p.mutHP( -dmg );
    act = "";
    std::string sdmg = std::to_string(dmg);
    act = " E deals " + sdmg + " to PC." ;
  }
  else
  {
    act = "";
    act = " E Attack missed! PC.";
  }
}

void Elf::attackedBy( Player &p ) 
{ 
  p.attackedBy( *this );
  p.attack( *this ); 
}
