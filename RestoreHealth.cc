#include "RestoreHealth.h"


RestoreHealth::RestoreHealth(Player * player) : Potion{player} {
	potiontype = "RH";
	if (this->getType() == "Drow") {
		this->mutHP(15);
	}
	else {
		this->mutHP(10);
	}
}

std::string RestoreHealth::getInfo() {
	return potiontype;
}

RestoreHealth::~RestoreHealth() {
//	delete player;
}

void RestoreHealth::attack( Human &e ) {}
void RestoreHealth::attack( Dwarf &e ) {}
void RestoreHealth::attack( Elf &e ) {}
void RestoreHealth::attack( Orc &e ) {}
void RestoreHealth::attack( Merchant &e ) {}
void RestoreHealth::attack( Dragon &e ) {}
void RestoreHealth::attack( Halfling &e ) {}
void RestoreHealth::attackedBy( Enemy &e ) {}

