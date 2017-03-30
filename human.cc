#include "human.h"

Human::Human() : Enemy( 140, 140, 20, 20, 20, 20, 0, "Human" ) {}
Human::~Human(){}

void Human::attack( Shade &p )
{
  std::cout << "Human Attacks Shade" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}

void Human::attack( Drow &p )
{
  std::cout << "Human Attacks Drow" << std::endl;
}

void Human::attack( Vampire &p )
{
  std::cout << "Human Attacks Vampire" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}

void Human::attack( Troll &p )
{
  std::cout << "Human Attacks Troll" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}


void Human::attack( Goblin &p )
{
  std::cout << "Human Attacks Drow" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}


void Human::attackedBy( Player &p ) { p.attack( *this ); }
