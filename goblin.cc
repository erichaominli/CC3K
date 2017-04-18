#include "goblin.h"

Goblin::Goblin() : Player( 110, 110, 15, 15, 20, 20, 0, "Goblin" ) {}
Goblin::~Goblin() {}

void Goblin::attack( Human &e )
{
  int dmg = damage( e );
  e.mutHP( -dmg );
  act = "";
  std::string sdmg = std::to_string(dmg);
  std::string hp = std::to_string(e.getHP());
  act = " PC deals " + sdmg + " to H (" + hp + " HP)." ;

}

void Goblin::attack( Dwarf &e )
{
  act = "";
  int dmg = damage( e );
  e.mutHP( -dmg );
  std::string sdmg = std::to_string(dmg);
  std::string hp = std::to_string(e.getHP());
  act = " PC deals " + sdmg + " to W (" + hp + " HP)." ;
}

void Goblin::attack( Elf &e )
{
  act = "";
  int dmg = damage( e );
  e.mutHP( -dmg );
  std::string sdmg = std::to_string(dmg);
  std::string hp = std::to_string(e.getHP());
  act = " PC deals " + sdmg + " to E (" + hp + " HP)." ;
}

void Goblin::attack( Orc  &e )
{
  act = "";
  int dmg = damage( e );
  e.mutHP( -dmg );
  std::string sdmg = std::to_string(dmg);
  std::string hp = std::to_string(e.getHP());
  act = " PC deals " + sdmg + " to O (" + hp + " HP)." ;
}

void Goblin::attack( Merchant &e )
{
  act = "";
  int dmg = damage( e );
  e.mutHP( -dmg );
  std::string sdmg = std::to_string(dmg);
  std::string hp = std::to_string(e.getHP());
  act = " PC deals " + sdmg + " to M (" + hp + " HP)." ;
}

void Goblin::attack( Dragon &e )
{
  act = "";
  int dmg = damage( e );
  e.mutHP( -dmg );
  std::string sdmg = std::to_string(dmg);
  std::string hp = std::to_string(e.getHP());
  act = " PC deals " + sdmg + " to D (" + hp + " HP)." ;
}

void Goblin::attack( Halfling &e )
{
  act = "";
  if ( fiftyFifty() )
  {
    int dmg = damage( e );
    e.mutHP( -dmg );
    std::string sdmg = std::to_string(dmg);
    std::string hp = std::to_string(e.getHP());
    act = " PC deals " + sdmg + " to L (" + hp + " HP)." ;

  }
  else
  {
  std::string hp = std::to_string(e.getHP());
  act = " PC attack missed! L (" + hp + " HP)." ;
  }
}

void Goblin::attackedBy( Enemy &e ) { e.attack( * this ); }
