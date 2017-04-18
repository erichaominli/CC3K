#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include "subscriptions.h"
class Subject;
class Cell;

class Observer {
 public:
  virtual ~Observer() = default;
};
#endif
