#ifndef _FLOOR_H_
#define _FLOOR_H_
#include <iostream>
#include <vector>
#include "chamber.h"
#include "cell.h"
#include "character.h"
#include "player.h"
#include <string>
#include <fstream>
#include "posn.h"
#include "BoostAtk.h"
#include "BoostDef.h"
#include "RestoreHealth.h"
#include "PoisonHealth.h"
#include "WoundAtk.h"
#include "WoundDef.h"
#include "Small.h"
#include "Normal.h"
#include "DragonHoard.h"
#include "MerchantHoard.h"
#include "result.h"
#include <stdexcept>
class Floor 
{ 
  std::vector<std::vector<Cell*>> theFloor;
  std::vector<Chamber*> theChambers;
  std::vector<Character*> theEnemies;
  std::vector<Character*> theDragons;
  std::string action; 
  bool readMap;
  int level, len, wid;
  Player* mainChar;

  public:
  
  std::ifstream& file;

  Floor( bool readMap, int lvl, std::ifstream& file, std::string cmd );
  ~Floor();
  void clearFloor();
  void move( Character* cp1, std::string direction );
  void moveEnemies();
  void init( std::ifstream& file );
  void clearAction();
  std::string isWon();
  bool isAtStairs();
  bool isAtPotion();
  bool isAtTreasure();
  void consumePotion();
  void consumeTreasure( std::string s );
  void set(int r, int c, Character* pc1 );
  Player* getMainChar();
  void newTurn();
  void attack(std::string direction);
  void slainEnemy( Enemy* e );
  friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};

#endif
