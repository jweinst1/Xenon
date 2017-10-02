#include "Xenon.h"
#include <iostream>

int main(int argc, char const *argv[]) {
        XenError nine("Error index %s should be %d", "foo", 6);
        std::cout << nine.what() << "\n";
        return 0;
}
