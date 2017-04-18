#include "chamber.h"

Chamber::Chamber() {}
Chamber::~Chamber() { theChamber.clear(); }

void Chamber::add( Cell* cp ) { theChamber.emplace_back( cp ); }

void Chamber::remove( int index )
{
  Cell* temp = theChamber.at( theChamber.size() - 1 );
  theChamber.at( theChamber.size() - 1 ) = theChamber.at( index );
  theChamber.at( index ) = temp;
  theChamber.pop_back();
}


void Chamber::placeChar( Character* cp )
{
  int x = rand() % theChamber.size();
  theChamber.at( x )->set( cp );
//  cp->mutRow( theChamber.at( x )->getRow() );
//  cp->mutCol( theChamber.at( x )->getCol() );
  remove( x );
}
