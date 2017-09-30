//example of static trie with switch statements and jump tables

int findInTrie(const char* str)
{
        switch(str[0])
        {
        case '+':
                switch(str[1])
                {
                case '+':
                        switch(str[2])
                        {
                        case '+':
                                return 2;
                        case '-':
                                return 6;
                        case '^': return 6;
                        case '#': return 1;
                        case '8': return 9;
                        case '`': return 28;
                        case '9': return 1999;
                        default:
                                return 2;
                        }
                case '-':
                        return 6;
                case '^': return 6;
                case '@': return 1;
                case '!': return 99;
                case '`': return 22;
                case '$': return 19;
                default:
                        return 2;
                }
                break;
        case '-':
                return 3;
        case '*':
                return 4;
        case '/':
                return 4;
        case '$':
                return 4;
        default:
                return 0;
        }
}
