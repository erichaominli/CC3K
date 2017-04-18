#include "MerchantHoard.h"

MerchantHoard::MerchantHoard(Player * player) : Treasure{player} {
	treasuretype = "MerchantHoard";
	this->mutGold(4);
}

std::string MerchantHoard::getInfo() {
	return treasuretype;
}

MerchantHoard::~MerchantHoard() {
}

void MerchantHoard::attack( Human &e ) {}
void MerchantHoard::attack( Dwarf &e ) {}
void MerchantHoard::attack( Elf &e ) {}
void MerchantHoard::attack( Orc &e ) {}
void MerchantHoard::attack( Merchant &e ) {}
void MerchantHoard::attack( Dragon &e ) {}
void MerchantHoard::attack( Halfling &e ) {}
void MerchantHoard::attackedBy( Enemy &e ) {}

