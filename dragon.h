#ifndef _DRAGON_H_
#define _DRAGON_H_
#include "player.h"
#include "enemy.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

class Dragon : public Enemy
{
  public:
  Dragon();
  ~Dragon();

  void attack( Shade &p );
  void attack( Drow &p );
  void attack( Vampire &p );
  void attack( Troll &p );
  void attack( Goblin &p );

  void attackedBy( Player &p ) ;
};
#endif

