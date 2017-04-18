#include "character.h"

std::string Character::getInfo() { return race; }

void Character::slain() {}
int Character::getScore() { return gold; }
int Character::getHP() { return HP; }
int Character::getBaseHP() { return baseHP; }
int Character::getAtk() { return atk; }
int Character::getBaseAtk() { return baseAtk; }
int Character::getDef() { return def; }
int Character::getBaseDef() { return baseDef; }
int Character::getGold() { return gold; }
int Character::getRow(){ return Row;}
int Character::getCol(){ return Col;}
std::string Character::getType(){ return type;}
std::string Character::getRace() { return race; }
char Character::getSymbol() { return symbol; }
void Character::setHP( int i ) { HP = i; }
void Character::setAtk( int i ) { atk = i; }
void Character::setDef( int i ) { def = i; }
void Character::setGold( int i ) { gold = i; }
bool Character::getDead(){ return dead; }
std::string Character::getAct() { return act; }
Character & Character:: operator=(const Character &other)
{
  if(this == &other) return *this;
  HP = other.HP; 
  baseHP = other.baseHP; 
  atk = other.atk; 
  baseAtk = other.baseAtk; 
  def = other.def; 
  baseDef = other.baseDef; 
  gold = other.gold; 
  race = other.race; 
  symbol = other.symbol;
  return *this;
}  

bool Character::fiftyFifty() 
{ 
srand( time(NULL) );
return rand() % 2; 
}

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

void Character::mutRow(int r){
  Row = r;
}

void Character::mutCol(int c){
  Col = c;
}

void Character::mutHP( int i )
{
  HP += i;
  if ( HP > baseHP ) HP = baseHP;
  if ( HP <= 0 ) 
  {
    HP = 0;
    dead = true;
  }
}

void Character::mutGold( int i )
{
  gold += i;
  if ( gold < 0 ) gold = 0;
}

void Character::clearAct() { act = ""; }
void Character::addToAct( std::string s ) { act = act + s; }

Character::Character( int HP, int baseHP, int atk, int baseAtk, int def, int baseDef, int gold, std::string race, char symbol, std::string type)
: HP{HP}, baseHP{baseHP}, atk{atk}, baseAtk{baseAtk},
  def{def}, baseDef{baseDef}, gold{gold}, race{race}, 
  symbol{symbol}, type{type}, dead{false}{}

Character::~Character() {}
