#include "halfling.h"

Halfling::Halfling() : Enemy( 100, 100, 15, 15, 20, 20, 0, "Halfling" ) {}
Halfling::~Halfling() {}

void Halfling::attack( Shade &p )
{
  std::cout << "Halfling Attacks Shade" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}

void Halfling::attack( Drow &p )
{
  std::cout << "Halfling Attacks Drow" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}

void Halfling::attack( Vampire &p )
{
  std::cout << "Halfling Attacks Vampire" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}

void Halfling::attack( Troll &p )
{
  std::cout << "Halfling Attacks Troll" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}

void Halfling::attack( Goblin &p )
{
  std::cout << "Halfling Attacks Drow" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}

void Halfling::attackedBy( Player &p ) { p.attack( *this ); }

