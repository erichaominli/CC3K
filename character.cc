#include "character.h"

int Character::getHP() { return HP; }
int Character::getBaseHP() { return baseHP; }
int Character::getAtk() { return atk; }
int Character::getBaseAtk() { return baseAtk; }
int Character::getDef() { return def; }
int Character::getBaseDef() { return baseDef; }
int Character::getGold() { return gold; }
std::string Character::getRace() { return race; }
void Character::setHP() { HP = baseHP; }
void Character::setAtk() { atk = baseAtk; }
void Character::setDef() { def = baseDef; }

bool Character::fiftyFifty() { return rand() % 2; }

int Character::damage( Character &defender )
{
  double a = atk;
  double b = defender.getDef();
  int dmg = ceil( ( 100 / ( 100 + b )  ) * a );
  return dmg;
}

void Character::mutAtk( int i )
{
  atk += i;
  if ( atk < 0 ) atk = 0;
}


void Character::mutDef( int i )
{
  def += i;
  if ( def < 0 ) def = 0;
}

void Character::mutHP( int i )
{
  HP += i;
  if ( HP > baseHP ) HP = baseHP;
  if ( HP <= 0 ) 
  {
    HP = 0;
    slain();
  }
}

void Character::mutGold( int i )
{
  gold += i;
  if ( gold < 0 ) gold = 0;
}

void Character::slain() { std::cout << getRace() << " is Slain" << std::endl; }

Character::Character( int HP, int baseHP, int atk, int baseAtk, int def, int baseDef, int gold, std::string race )
: HP{HP}, baseHP{baseHP}, atk{atk}, baseAtk{baseAtk},
  def{def}, baseDef{baseDef}, gold{gold}, race{race} {}

Character::~Character() {}
