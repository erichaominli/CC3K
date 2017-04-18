#ifndef BOOSTATK_H
#define BOOSTATK_H
#include "Potion.h"

class BoostAtk : public Potion {
	public:
	BoostAtk(Player * player);
	std::string getInfo() override;
	~BoostAtk();
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
