#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "character.h"

class Human;
class Dwarf;
class Elf;
class Orc;
class Merchant;
class Dragon;
class Halfling;
class Enemy;

class Player : public Character
{
  
  public: 

  virtual ~Player();  
  Player( int HP, int baseHP, int atk, int baseAtk, int def, int baseDef, int gold, std::string race, char symbol = '@' );

  virtual void attack( Human &e ) = 0;
  virtual void attack( Dwarf &e ) = 0;
  virtual void attack( Elf &e ) = 0;
  virtual void attack( Orc &e ) = 0;
  virtual void attack( Merchant &e ) = 0;
  virtual void attack( Dragon &e ) = 0;
  virtual void attack( Halfling &e ) = 0;

  virtual void attackedBy( Enemy &e ) = 0;

};

#endif
