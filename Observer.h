#ifndef _OBSERVER_H_
#define _OBSERVER_H_

// We want to use observer pattern, however, we do not know who to use it, so this .h file is never used but we do not want to delete it

class Cell;

enum class SubscriptionType { All, Around };

class Observer {
  public:
    virtual void notify(Cell &c, char type) = 0;  // c is the Cell that called the notify method (PLAN TO USE IT)
    virtual SubscriptionType subType() = 0;
    virtual ~Observer() = default;
};





#endif


