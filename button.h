#ifndef BUTTON_H
#define BUTTON_H
#define BUTTON_WAIT 2
class Button{
  private:
    char pin_;
    bool pullup_=false;
    bool inverted_=false;
    bool state_=false;
    bool forced_=false;
    bool debounce_=true;
  public:
    Button(char pin,bool pullup,bool inverted,bool debounce):pin_{pin},pullup_{pullup},inverted_{inverted},debounce_{debounce} {}
    Button(char pin,bool pullup,bool inverted):pin_{pin},pullup_{pullup},inverted_{inverted} {}
    Button(char pin,bool pullup):pin_{pin},pullup_{pullup} {}
    Button(char pin):pin_{pin} {}
    void init();// init the button [required]
    bool read();//  /!\ wait if debounce is activated
    void forceState(bool s);// bypass button
    void reset();// "unbypass" the button
};
#endif
