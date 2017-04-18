#include "DragonHoard.h"

DragonHoard::DragonHoard(Player * player) : Treasure{player} {
	treasuretype = "DragonHoard";
	this->mutGold(6);
}

std::string DragonHoard::getInfo() {
	return treasuretype;
}

DragonHoard::~DragonHoard() {
}

void DragonHoard::attack( Human &e ) {}
void DragonHoard::attack( Dwarf &e ) {}
void DragonHoard::attack( Elf &e ) {}
void DragonHoard::attack( Orc &e ) {}
void DragonHoard::attack( Merchant &e ) {}
void DragonHoard::attack( Dragon &e ) {}
void DragonHoard::attack( Halfling &e ) {}
void DragonHoard::attackedBy( Enemy &e ) {}

