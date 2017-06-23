#include <ctype.h>
#include "../head/tokenstate.h"

/**
 * Function that takes in the code, and a bool.
 * the bool determines if the tokenizer is currently set at a token or needs to cut for a diff token.
 * state 0: base
 * state 1: name literal
 * state 2: numeric literal
 * state 3: string literal
 * state 4: single char token
 * state 5: - token to -> or -
 * state 6: bool operators
 * state 7: double or float
 */
void tokenState(const char* input, bool* active)
{
    static int state = 0;
    switch(state)
    {
        //base state
       case 0:
             if(isspace(*input));
             else if(isalpha(*input))
             {
                state = 1;
                *active = true;
             }
             else if(isdigit(*input))
             {
                state = 2;
                *active = true;
             }
             else switch(*input)
             {
                case '"':
                    state = 3;
                    *active = true;
                    break;
                case '+':
                case '@':
                case '|':
                case '&':
                case '*':
                case '/':
                case '[':
                case ']':
                case '%':
                    state = 4;
                    *active = true;
                    break;
                case '-':
                    state = 5;
                    *active = true;
                    break;
                //bool comparison states
                case '>':
                case '<':
                case '=':
                    state = 6;
                    *active = true;
                    break;
             }
             break;
        //name literal state
        case 1:
            if(!(isalpha(*input) || isdigit(*input) || *input == '_'))
            {
                state = 0;
                *active = false;
            }
            break;
        case 2:
            if(*input == '.')
            {
                state = 7;
                //active stays true due to float
            }
            else if(!isdigit(*input))
            {
                state = 0;
                *active = false;
            }
            break;
    }
}