#include "arduino.h"
#include "button.h"
void Button::init(){
  if(pullup_)pinMode(pin_,INPUT_PULLUP);
  else pinMode(pin_,INPUT);
}
bool Button::read(){
  if(!forced_){
    bool v = digitalRead(pin_)?!inverted_:inverted_;
    if(debounce_){
      if(v != state_){
        delay(BUTTON_WAIT);
        bool w = digitalRead(pin_)?!inverted_:inverted_;
        if(v == w) state_ = v;
      }
    }else{
      state_ = v;
    }
  }
  return state_;
}
void Button::forceState(bool s){
  forced_=true;
  state_=s;
}
void Button::reset(){
  forced_=false;
}

