#include "elf.h"

Elf::Elf() : Enemy( 140, 140, 30, 30, 10, 10, 0, "Elf" ) {}
Elf::~Elf() {}

void Elf::attack( Shade &p )
{
  std::cout << "Elf Attacks Shade" << std::endl;
  int dmg = damage( p );
  if ( fiftyFifty() )
  {
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
    if ( p.getHP() <= 0 ) return;
  }
  else std::cout << "missed" << std::endl;
  std::cout << "Elf Attacks Shade" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}

void Elf::attack( Drow &p )
{
  std::cout << "Elf Attacks Drow" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}


void Elf::attack( Vampire &p )
{
  std::cout << "Elf Attacks Vampire" << std::endl;
  int dmg = damage( p );
  if ( fiftyFifty() )
  {
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
    if ( p.getHP() <= 0 ) return;
  }
  else std::cout << "missed" << std::endl;
  std::cout << "Elf Attacks Vampire" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}

void Elf::attack( Troll &p )
{
  std::cout << "Elf Attacks Troll" << std::endl;
  int dmg = damage( p );
  if ( fiftyFifty() )
  {
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
    if ( p.getHP() <= 0 ) return;
  }
  else std::cout << "missed" << std::endl;
  std::cout << "Elf Attacks Troll" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}

void Elf::attack( Goblin &p )
{
  std::cout << "Elf Attacks Goblin" << std::endl;
  int dmg = damage( p );
  if ( fiftyFifty() )
  {
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
    if ( p.getHP() <= 0 ) return;
  }
  else std::cout << "missed" << std::endl;
  std::cout << "Elf Attacks Goblin" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}

void Elf::attackedBy( Player &p ) { p.attack( *this ); }

