#ifndef _HUMAN_H_
#define _HUMAN_H_
#include "player.h"
#include "enemy.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

class Human : public Enemy
{
  public:
  Human();
  ~Human();
  void attack( Shade &s );
  void attack( Drow &d );
  void attack( Vampire &v );
  void attack( Troll &t );
  void attack( Goblin &g );
  
  void attackedBy( Player &p );
};
#endif
