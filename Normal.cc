#include "Normal.h"

Normal::Normal(Player * player) : Treasure{player} {
	treasuretype = "Normal";
	this->mutGold(2);
}

std::string Normal::getInfo() {
	return treasuretype;
}

Normal::~Normal() {}

void Normal::attack( Human &e ) {}
void Normal::attack( Dwarf &e ) {}
void Normal::attack( Elf &e ) {}
void Normal::attack( Orc &e ) {}
void Normal::attack( Merchant &e ) {}
void Normal::attack( Dragon &e ) {}
void Normal::attack( Halfling &e ) {}
void Normal::attackedBy( Enemy &e ) {}


