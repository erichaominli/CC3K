#include "dwarf.h"

Dwarf::Dwarf() : Enemy( 100, 100, 20, 20, 30, 30, 0, "Dwarf" ) {}
Dwarf::~Dwarf() {}

void Dwarf::attack( Shade &p )
{
  std::cout << "Dwarf Attacks Shade" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}


void Dwarf::attack( Drow &p )
{
  std::cout << "Dwarf Attacks Drow" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}


void Dwarf::attack( Vampire &p )
{
  std::cout << "Dwarf Attacks Vampire" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}

void Dwarf::attack( Troll &p )
{
  std::cout << "Dwarf Attacks Troll" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}


void Dwarf::attack( Goblin &p )
{
  std::cout << "Dwarf Attacks Drow" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}


void Dwarf::attackedBy( Player &p ) { p.attack( *this ); }
