#ifndef BOOSTDEF_H
#define BOOSTDEF_H
#include "Potion.h"


class BoostDef : public Potion {
	public:
	BoostDef(Player * player);
	std::string getInfo() override;
	~BoostDef();
        void attack( Human &e ) override;
        void attack( Dwarf &e ) override;
        void attack( Elf &e ) override;
        void attack( Orc &e ) override;
        void attack( Merchant &e ) override;
        void attack( Dragon &e ) override;
        void attack( Halfling &e ) override;
        void attackedBy( Enemy &e ) override;
};

#endif

