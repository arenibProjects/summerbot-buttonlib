#include "arduino.h"
#include "starter.h"
void Starter::init(){
  button_->init();
}
void Starter::arm(){
  armed_=true;
  button_->reset();
}
void Starter::disarm(){
  armed_=false;
  primed_=false;
  button_->forceState(0);
}
void Starter::reset(){
  launched_=false;
  disarm();
}
void Starter::forceLaunch(){
  arm();
  launched_=true;
  primed_=true;
}
bool Starter::isLaunched(){
  if(!launched_ && armed_){
    bool v = button_->read();
    if(primed_ && !v)launched_ = true;
    else if(v) primed_=true;
  }
  return launched_;
}

bool Starter::isPrimed(){
  if(!primed_ && button_->read()){
      primed_=true;
  }
  return primed_;
}
bool Starter::isArmed(){
  return armed_;
}
