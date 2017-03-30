#ifndef _MERCHANT_H_
#define _MERCHANT_H_
#include "player.h"
#include "enemy.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

class Merchant : public Enemy
{
  public:
  Merchant();
  ~Merchant();

  static int agro;  
  void attack( Shade &p );
  void attack( Drow &p );
  void attack( Vampire &p );
  void attack( Troll &p );
  void attack( Goblin &p );

  void attackedBy( Player &p ) ;
};
#endif

