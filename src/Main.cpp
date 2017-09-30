#include "Xenon.h"
#include <iostream>

int main(int argc, char const *argv[]) {
        for (size_t i = 0; i < argc; i++) {
                std::cout << argv[i] << "\n";
        }
        return 0;
}
