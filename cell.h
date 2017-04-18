#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include <vector>
#include <utility>
#include "textdisplay.h"
#include "subject.h"
#include "observer.h"
#include "player.h"
#include "enemy.h"
#include "subscriptions.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include "merchant.h"

class Cell 
{

  std::vector< Cell* > nbors; 
  Character* cp;
  char symbol;
  std::string name;
  int row, col;
  bool emov, pmov, stair, pot, tre, dh;

 public:

  void attachNbor( Cell* cell );
  void notifyNbors();

  Cell( char sym, int r, int c );
  ~Cell();
  void set( Character* cp1);       
  void setStair();
  void setPotion();
  void setTreasure( std::string );
  void removePotion();
  void removeTreasure();
  void unSet();
  void unSetDh();
  char getSymbol() const;
  std::string getname() const;
  std::vector<Cell*>* getNbors();
  Character* getCp() const;
  int getRow() const;
  int getCol() const;
  bool getEmov() const;
  bool getPmov() const;
  bool getStair() const;
  bool getPot() const;
  bool getTre() const;
  bool getDh() const;
  std::string getTreasure() const;
  void link( Cell* nbor );
  void notify( Cell &whoNoitified );

};
#endif
