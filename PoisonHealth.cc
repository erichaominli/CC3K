#include "PoisonHealth.h"


PoisonHealth::PoisonHealth(Player * player) : Potion{player} {
	potiontype = "PH";
        if (this->getType() == "Drow") {
                this->mutHP(-15);
        }
        else {
                this->mutHP(-10);
        }
}


std::string PoisonHealth::getInfo() {
	return potiontype;
}

PoisonHealth::~PoisonHealth() {
//	delete player;
}

void PoisonHealth::attack( Human &e ) {}
void PoisonHealth::attack( Dwarf &e ) {}
void PoisonHealth::attack( Elf &e ) {}
void PoisonHealth::attack( Orc &e ) {}
void PoisonHealth::attack( Merchant &e ) {}
void PoisonHealth::attack( Dragon &e ) {}
void PoisonHealth::attack( Halfling &e ) {}
void PoisonHealth::attackedBy( Enemy &e ) {}

