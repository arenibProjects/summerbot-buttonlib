#ifndef STARTER_H
#define STARTER_H
#include "button.h"
class Starter{
  private:
    Button* button_;
    bool armed_=false;
    bool primed_=false;
    bool launched_=false;
  public:
    Starter(char pin,bool pullup,bool inverted){
      button_= new Button(pin,pullup,inverted);
      button_->forceState(0);
    }
    void init();// init the button [required]
    void arm();// enable the button (disabled by default)
    void disarm();// disable the button
    void reset();// "unlaunch" and disarm the button
    void forceLaunch();// to bypass the button
    bool isLaunched();// key pulled
    bool isPrimed();// key inserted
    bool isArmed();// active
};
#endif
