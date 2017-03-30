#ifndef _DWARF_H_
#define _DWARF_H_
#include "player.h"
#include "enemy.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

class Dwarf : public Enemy 
{
  public:
  Dwarf();
  ~Dwarf();
  
  void attack( Shade &s );
  void attack( Drow &d );
  void attack( Vampire &v );
  void attack( Troll &t );
  void attack( Goblin &g );

  void attackedBy( Player &p ) ;
};
#endif

