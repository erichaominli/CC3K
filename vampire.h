#ifndef _VAMPIRE_H_
#define _VAMPIRE_H_
#include "player.h"
#include "enemy.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"
class Vampire : public Player
{
  public:
  Vampire();
  ~Vampire();

  void mutHP( int i ) override;

  void attack( Human &h );
  void attack( Dwarf &d );
  void attack( Elf &e );
  void attack( Orc &o );
  void attack( Merchant &m );
  void attack( Dragon &d );
  void attack( Halfling &h );

  void attackedBy( Enemy &e );

};

#endif

