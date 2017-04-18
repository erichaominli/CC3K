#ifndef NORMAL_H
#define NORMAL_H
#include "Treasure.h"

class Normal : public Treasure {
	public:
	Normal(Player * player);
	std::string getInfo() override;
	~Normal();
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
