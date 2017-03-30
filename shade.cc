#include "shade.h"

Shade::Shade() : Player( 125, 125, 25, 25, 25, 25, 0, "Shade" ) {} 
Shade::~Shade() {}


void Shade::attack( Human &e )
{
  std::cout << "Shade Attacks Human" << std::endl;
  int dmg = damage( e );
  std::cout << dmg << std::endl;
  e.mutHP( -dmg );
  std::cout << e.getHP() << std::endl;
}

void Shade::attack( Dwarf &e ) 
{
  std::cout << "Shade Attacks Dwarf" << std::endl;
  int dmg = damage( e );
  e.mutHP( -dmg );
  std::cout << e.getHP() << std::endl;
}

void Shade::attack( Elf &e )
{
  std::cout << "Shade Attacks Elf" << std::endl;
  int dmg = damage( e );
  e.mutHP( -dmg );
  std::cout << e.getHP() << std::endl;
}

void Shade::attack( Orc  &e )
{
  std::cout << "Shade Attacks Orc" << std::endl;
  int dmg = damage( e );
  e.mutHP( -dmg );
  std::cout << e.getHP() << std::endl;
}

void Shade::attack( Merchant &e )
{
  std::cout << "Shade Attacks Merchant" << std::endl;
  int dmg = damage( e );
  e.mutHP( -dmg );
  std::cout << e.getHP() << std::endl;
}

void Shade::attack( Dragon &e )
{
  std::cout << "Shade Attacks Dragon" << std::endl;
  int dmg = damage( e );
  e.mutHP( -dmg );
  std::cout << e.getHP() << std::endl;
}

void Shade::attack( Halfling &e )
{
  std::cout << "Shade Attacks Halfling" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( e );
    std::cout << dmg << std::endl;
    e.mutHP( -dmg );
    std::cout << e.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}

void Shade::attackedBy( Enemy &e ) { e.attack( *this ); }

