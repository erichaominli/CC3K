#ifndef _GOBLIN_H_
#define _GOBLIN_H_
#include "player.h"
#include "enemy.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"

class Goblin : public Player
{
  public:
  Goblin();
  ~Goblin();

  void attack( Human &e );
  void attack( Dwarf &e );
  void attack( Elf &e );
  void attack( Orc &e );
  void attack( Merchant &e );
  void attack( Dragon &e );
  void attack( Halfling &e );

  void attackedBy( Enemy &e );
};

#endif

