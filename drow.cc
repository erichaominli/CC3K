#include "drow.h"

Drow::Drow() : Player( 150, 150, 25, 25, 15, 15, 0, "Drow" ) {}
Drow::~Drow() {}

void Drow::attack( Human &e )
{
  int dmg = damage( e );
  e.mutHP( -dmg );
  act = "";
  std::string sdmg = std::to_string(dmg);
  std::string hp = std::to_string(e.getHP());
  act = " PC deals " + sdmg + " to H (" + hp + " HP)." ;

}

void Drow::attack( Dwarf &e )
{
  int dmg = damage( e );
  e.mutHP( -dmg );
  act = "";
  std::string sdmg = std::to_string(dmg);
  std::string hp = std::to_string(e.getHP());
  act = " PC deals " + sdmg + " to W (" + hp + " HP)." ;
}

void Drow::attack( Elf &e )
{
  int dmg = damage( e );
  e.mutHP( -dmg );
  act = "";
  std::string sdmg = std::to_string(dmg);
  std::string hp = std::to_string(e.getHP());
  act = " PC deals " + sdmg + " to E (" + hp + " HP)." ;
}

void Drow::attack( Orc  &e )
{
  int dmg = damage( e );
  e.mutHP( -dmg );
  act = "";
  std::string sdmg = std::to_string(dmg);
  std::string hp = std::to_string(e.getHP());
  act = " PC deals " + sdmg + " to O (" + hp + " HP)." ;
}

void Drow::attack( Merchant &e )
{
  int dmg = damage( e );
  e.mutHP( -dmg );
  act = "";
  std::string sdmg = std::to_string(dmg);
  std::string hp = std::to_string(e.getHP());
  act = " PC deals " + sdmg + " to M (" + hp + " HP)." ;

}

void Drow::attack( Dragon &e )
{
  int dmg = damage( e );
  e.mutHP( -dmg );
  act = "";
  std::string sdmg = std::to_string(dmg);
  std::string hp = std::to_string(e.getHP());
  act = " PC deals " + sdmg + " to D (" + hp + " HP)." ;
}

void Drow::attack( Halfling &e )
{
  if ( fiftyFifty() )
  {
    int dmg = damage( e );
    e.mutHP( -dmg ); 
    act = "";
    std::string sdmg = std::to_string(dmg);
    std::string hp = std::to_string(e.getHP());
    act = " PC deals " + sdmg + " to L (" + hp + " HP)." ;
  }
  else 
  {
    act = "";
    std::string hp = std::to_string(e.getHP());
    act = " PC attack missed! L (" + hp + " HP)." ;
  }   
}

void Drow::attackedBy( Enemy &e ) { e.attack( * this ); }
