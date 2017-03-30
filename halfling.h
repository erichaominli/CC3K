#ifndef _HALFLING_H_
#define _HALFLING_H_
#include "player.h"
#include "enemy.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

class Halfling : public Enemy
{
  public:
  Halfling();
  ~Halfling();

  void attack( Shade &p );
  void attack( Drow &p );
  void attack( Vampire &p );
  void attack( Troll &p );
  void attack( Goblin &p );
  void attackedBy( Player &p );
};
#endif

