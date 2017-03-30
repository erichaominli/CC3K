#include "drow.h"

Drow::Drow() : Player( 150, 150, 25, 25, 15, 15, 0, "Drow" ) {}
Drow::~Drow() {}

void Drow::attack( Human &e )
{
  std::cout << "Drow Attacks Human" << std::endl;
  int dmg = damage( e );
  std::cout << dmg << std::endl;
  e.mutHP( -dmg );
  std::cout << e.getHP() << std::endl;
}

void Drow::attack( Dwarf &e )
{
  std::cout << "Drow Attacks Dwarf" << std::endl;
  int dmg = damage( e );
  std::cout << dmg << std::endl;
  e.mutHP( -dmg );
  std::cout << e.getHP() << std::endl;
}

void Drow::attack( Elf &e )
{
  std::cout << "Drow Attacks Elf" << std::endl;
  int dmg = damage( e );
  std::cout << dmg << std::endl;
  e.mutHP( -dmg );
  std::cout << e.getHP() << std::endl;
}

void Drow::attack( Orc  &e )
{
  std::cout << "Drow Attacks Orc" << std::endl;
  int dmg = damage( e );
  std::cout << dmg << std::endl;
  e.mutHP( -dmg );
  std::cout << e.getHP() << std::endl;
}

void Drow::attack( Merchant &e )
{
  std::cout << "Drow Attacks Merchant" << std::endl;
  int dmg = damage( e );
  std::cout << dmg << std::endl;
  e.mutHP( -dmg );
  std::cout << e.getHP() << std::endl;
}

void Drow::attack( Dragon &e )
{
  std::cout << "Drow Attacks Dragon" << std::endl;
  int dmg = damage( e );
  std::cout << dmg << std::endl;
  e.mutHP( -dmg );
  std::cout << e.getHP() << std::endl;
}

void Drow::attack( Halfling &e )
{
  std::cout << "Drow Attacks Halfling" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( e );
    std::cout << dmg << std::endl;
    e.mutHP( -dmg );
    std::cout << e.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}

void Drow::attackedBy( Enemy &e ) { e.attack( * this ); }
