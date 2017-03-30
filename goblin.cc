#include "goblin.h"

Goblin::Goblin() : Player( 110, 110, 15, 15, 20, 20, 0, "Goblin" ) {}
Goblin::~Goblin() {}

void Goblin::attack( Human &e )
{
  std::cout << "goblin Attacks Human" << std::endl;
  int dmg = damage( e );
  std::cout << dmg << std::endl;
  e.mutHP( -dmg );
  std::cout << e.getHP() << std::endl;
}

void Goblin::attack( Dwarf &e )
{
  std::cout << "Goblin Attacks Dwarf" << std::endl;
  int dmg = damage( e );
  std::cout << dmg << std::endl;
  e.mutHP( -dmg );
  std::cout << e.getHP() << std::endl;
}

void Goblin::attack( Elf &e )
{
  std::cout << "Goblin Attacks Elf" << std::endl;
  int dmg = damage( e );
  std::cout << dmg << std::endl;
  e.mutHP( -dmg );
  std::cout << e.getHP() << std::endl;
}

void Goblin::attack( Orc  &e )
{
  std::cout << "Goblin Attacks Orc" << std::endl;
  int dmg = damage( e );
  std::cout << dmg << std::endl;
  e.mutHP( -dmg );
  std::cout << e.getHP() << std::endl;
}

void Goblin::attack( Merchant &e )
{
  std::cout << "Goblin Attacks Merchant" << std::endl;
  int dmg = damage( e );
  std::cout << dmg << std::endl;
  e.mutHP( -dmg );
  std::cout << e.getHP() << std::endl;
}

void Goblin::attack( Dragon &e )
{
  std::cout << "Goblin Attacks Dragon" << std::endl;
  int dmg = damage( e );
  std::cout << dmg << std::endl;
  e.mutHP( -dmg );
  std::cout << e.getHP() << std::endl;
}

void Goblin::attack( Halfling &e )
{
  std::cout << "Goblin Attacks Halfling" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( e );
    std::cout << dmg << std::endl;
    e.mutHP( -dmg );
    std::cout << e.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}

void Goblin::attackedBy( Enemy &e ) { e.attack( * this ); }
