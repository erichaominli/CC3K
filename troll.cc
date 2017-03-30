#include "troll.h"

Troll::Troll() : Player( 120, 120, 25, 25, 21, 15, 0, "Troll" ) {}
Troll::~Troll() {}

void Troll::attack( Human &e )
{
  std::cout << "Troll Attacks Human" << std::endl;
  int dmg = damage( e );
  std::cout << dmg << std::endl;
  e.mutHP( -dmg );
  std::cout << e.getHP() << std::endl;
}

void Troll::attack( Dwarf &e )
{
  std::cout << "troll Attacks Dwarf" << std::endl;
  int dmg = damage( e );
  std::cout << dmg << std::endl;
  e.mutHP( -dmg );
  std::cout << e.getHP() << std::endl;
}

void Troll::attack( Elf &e )
{
  std::cout << "Troll Attacks Elf" << std::endl;
  int dmg = damage( e );
  std::cout << dmg << std::endl;
  e.mutHP( -dmg );
  std::cout << e.getHP() << std::endl;
}

void Troll::attack( Orc  &e )
{
  std::cout << "Troll Attacks Orc" << std::endl;
  int dmg = damage( e );
  std::cout << dmg << std::endl;
  e.mutHP( -dmg );
  std::cout << e.getHP() << std::endl;
}

void Troll::attack( Merchant &e )
{
  std::cout << "Troll Attacks Merchant" << std::endl;
  int dmg = damage( e );
  std::cout << dmg << std::endl;
  e.mutHP( -dmg );
  std::cout << e.getHP() << std::endl;
}

void Troll::attack( Dragon &e )
{
  std::cout << "Troll Attacks Dragon" << std::endl;
  int dmg = damage( e );
  std::cout << dmg << std::endl;
  e.mutHP( -dmg );
  std::cout << e.getHP() << std::endl;
}

void Troll::attack( Halfling &e )
{
  std::cout << "Troll Attacks Halfling" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( e );
    std::cout << dmg << std::endl;
    e.mutHP( -dmg );
    std::cout << e.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}

void Troll::attackedBy( Enemy &e ) { e.attack( * this ); }
