#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>

class Character 
{

  protected:

  int HP;
  int baseHP;
  int atk;
  int baseAtk;
  int def;
  int baseDef;
  int gold;
  std::string race;

  public:

  Character( int HP, int baseHP, int atk, int baseAtk, int def, int baseDef, int gold, std::string race );
  virtual ~Character();

  int getHP();
  int getAtk();
  int getDef();
  int getGold();
  int getBaseHP();
  int getBaseAtk();
  int getBaseDef();
  void setHP();
  void setAtk();
  void setDef();
  std::string getRace();
  virtual int damage( Character &defender );
  virtual void mutAtk( int i );
  virtual void mutDef( int i );
  virtual void mutHP( int i );
  virtual void mutGold( int i );
  virtual void slain();
  virtual bool fiftyFifty(); 
};
#endif
