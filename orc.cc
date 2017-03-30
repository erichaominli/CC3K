#include "orc.h"

Orc::Orc() : Enemy( 180, 180, 30, 30, 25, 25, 0, "Orc" ) {}
Orc::~Orc() {}

void Orc::attack( Shade &p )
{
  std::cout << "Orc Attacks Shade" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}

void Orc::attack( Drow &p )
{
  std::cout << "Orc Attacks Drow" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}

void Orc::attack( Vampire &p )
{
  std::cout << "Orc Attacks Vampire" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}

void Orc::attack( Troll &p )
{
  std::cout << "Orc Attacks Troll" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}

void Orc::attack( Goblin &p )
{
  std::cout << "Orc Attacks Goblin" << std::endl;
  if ( fiftyFifty() )
  {
    double a = atk;
    double b = p.getDef();
    int dmg = ceil( 1.5 * ( 100 / ( 100 + b )  ) * a );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}

void Orc::attackedBy( Player &p ) { p.attack( *this ); }

