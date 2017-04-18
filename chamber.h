#ifndef _CHAMBER_H_
#define _CHAMBER_H_
#include <vector>
#include <iostream>
#include "character.h"
#include <cstdlib>
#include <iostream>
#include "posn.h"
#include "cell.h"

class Chamber 
{ 
  public:
  std::vector<Cell*> theChamber; 
  
  public:

  Chamber();
  ~Chamber();

  void add( Cell* cp );
  void placeChar( Character* cp );
  void remove( int index );
};

#endif
