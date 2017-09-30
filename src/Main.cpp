#include "Xenon.h"
#include <iostream>

int main(int argc, char const *argv[]) {
        std::cout << XenEvent::strToEvType(argv[1]) << "\n";
        return 0;
}
