#include "dragon.h"

Dragon::Dragon() : Enemy( 150, 150, 30, 30, 25, 25, 0, "Dragon" ) {}
Dragon::~Dragon() {}

void Dragon::attack( Shade &s )
{
  std::cout << "Draogn Attacks Shade" << std::endl;
}

void Dragon::attack( Drow &d )
{
  std::cout << "Dragon Attacks Drow" << std::endl;
}

void Dragon::attack( Vampire &v )
{
  std::cout << "Draogn Attacks Vampire" << std::endl;
}

void Dragon::attack( Troll &t )
{
  std::cout << "Dragon Attacks Troll" << std::endl;
}

void Dragon::attack( Goblin &g )
{
  std::cout << "Dragon Attacks Drow" << std::endl;
}

void Dragon::attackedBy( Player &p ) { p.attack( *this ); }

