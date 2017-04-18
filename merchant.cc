#include "merchant.h"

int Merchant::agro = false;

Merchant::Merchant() : Enemy( 30, 30, 70, 70, 25, 25, 0, "Merchant", 'M' ) {}
Merchant::~Merchant() {}

void Merchant::attack( Shade &p )
{
  if (Merchant::agro)
  {
    if ( fiftyFifty() )
    {
      int dmg = damage( p );
      p.mutHP( -dmg );
      act = "";
      std::string sdmg = std::to_string(dmg);
      act = " M deals " + sdmg + " to PC" ;
    }
    else
    {
      act = "";
      act = " M Attack missed! PC ";
    }
  }
}

void Merchant::attack( Drow &p )
{
  if ( Merchant::agro )
  {
    if ( fiftyFifty() )
    {
      int dmg = damage( p );
      p.mutHP( -dmg );
      act = "";
      std::string sdmg = std::to_string(dmg);
      act = " M deals " + sdmg + " to PC" ;
    }
    else
    {
      act = "";
      act = " M Attack missed! PC ";
    }
  }
}

void Merchant::attack( Vampire &p )
{
  if ( Merchant::agro )
  {
    if ( fiftyFifty() )
    {
      int dmg = damage( p );
      p.mutHP( -dmg );
      act = "";
      std::string sdmg = std::to_string(dmg);
      act = " M deals " + sdmg + " to PC" ;
    }
    else
    {
      act = "";
      act = " M Attack missed! PC ";
    }
  }
}

void Merchant::attack( Troll &p )
{ 
  if ( Merchant::agro )
  {
    if ( fiftyFifty() )
    {
      int dmg = damage( p );
      p.mutHP( -dmg );
      act = "";
      std::string sdmg = std::to_string(dmg);
      act = " M deals " + sdmg + " to PC" ;
    }
    else
    {
      act = "";
      act = " M Attack missed! PC ";
    }
  }
}

void Merchant::attack( Goblin &p )
{
  if ( Merchant::agro )
  {
    if ( fiftyFifty() )
    {
      int dmg = damage( p );
      p.mutHP( -dmg );
      act = "";
      std::string sdmg = std::to_string(dmg);
      act = " M deals " + sdmg + " to PC" ;
    }
    else
    {
      act = "";
      act = " M Attack missed! PC ";
    }
  }
}

void Merchant::attackedBy( Player &p ) 
{ 
  Merchant::agro = true;
  p.attack( *this ); 
  p.attackedBy( *this );
}

