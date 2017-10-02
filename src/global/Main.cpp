#include "Xenon.h"
#include "CharSet.h"
#include <iostream>

int main(int argc, char const *argv[]) {
        CharSet nums("0123478");
        std::cout << nums.containsAll("31202");
        return 0;
}
