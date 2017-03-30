#ifndef _ORC_H_
#define _ORC_H_
#include "player.h"
#include "enemy.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

class Orc : public Enemy
{
  public:
  Orc();
  ~Orc();

  void attack( Shade &p );
  void attack( Drow &p );
  void attack( Vampire &p );
  void attack( Troll &p );
  void attack( Goblin &p );

  void attackedBy( Player &p ) ;
};
#endif

