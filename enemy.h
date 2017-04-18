#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "character.h"

class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;
class Player;

class Enemy : public Character
{
  public:

  Enemy( int HP, int baseHP, int atk, int baseAtk, int def, int baseDef, int gold, std::string race, char symbol );  
  virtual ~Enemy();

  virtual void attack( Shade &p ) = 0;
  virtual void attack( Drow &p ) = 0;
  virtual void attack( Vampire &p ) = 0;
  virtual void attack( Troll &p ) = 0;
  virtual void attack( Goblin &p ) = 0;
  virtual void attackedBy( Player &p ) = 0;

};
#endif
