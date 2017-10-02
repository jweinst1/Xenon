#include "Xenon.h"
#include <iostream>

int main(int argc, char const *argv[]) {
        CharBuf foo;
        foo.append('f');
        foo.append('g');
        foo.append('\n');
        std::cout << foo.data();
        return 0;
}
