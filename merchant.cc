#include "merchant.h"

int Merchant::agro = false;

Merchant::Merchant() : Enemy( 30, 30, 70, 70, 25, 25, 0, "Merchant" ) {}
Merchant::~Merchant() {}

void Merchant::attack( Shade &p )
{
  std::cout << "Merchant Attacks Shade" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}

void Merchant::attack( Drow &p )
{
  std::cout << "Merchant Attacks Drow" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}

void Merchant::attack( Vampire &p )
{
  std::cout << "Merchant Attacks Vampire" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}

void Merchant::attack( Troll &p )
{
  std::cout << "Merchant Attacks Troll" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}

void Merchant::attack( Goblin &p )
{
  std::cout << "Merchant Attacks Goblin" << std::endl;
  if ( fiftyFifty() )
  {
    int dmg = damage( p );
    std::cout << dmg << std::endl;
    p.mutHP( -dmg );
    std::cout << p.getHP() << std::endl;
  }
  else std::cout << "missed" << std::endl;
}

void Merchant::attackedBy( Player &p ) 
{ 
  agro = true;
  p.attack( *this ); 
}

