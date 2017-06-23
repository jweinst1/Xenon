#ifndef TOKEN_STATE_H
#define TOKEN_STATE_H
#include <stdbool.h>


extern "C" {

  //modifies and determines tokenizer state
  void tokenState(const char* input, bool* active);  
}


#endif