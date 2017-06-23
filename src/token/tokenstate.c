#include <ctype.h>
#include "../head/tokenstate.h"

/**
 * Function that takes in the code, and a bool.
 * the bool determines if the tokenizer is currently set at a token or needs to cut for a diff token.
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
                case '*':
                case '/':
                case '[':
                case ']':
                case '%':
                    state = 4;
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
    }
}