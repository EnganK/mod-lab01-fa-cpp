// Copyright 2022 UNN-IASR
#include <iostream>
#include "fun.h"

int main() {
    const char* testStr1 = "awfwaff 123 hjsakldfhl 13geg";
    const char* testStr2 = "Awgawgg Awgawgawg wg Qsdgeag123 AWfgawga";
    const char* testStr3 = "awfawg awff awag awgawg tfdbr";

    std::cout << "Test faStr1: " << faStr1(testStr1) << std::endl;
    std::cout << "Test faStr2: " << faStr2(testStr2) << std::endl;
    std::cout << "Test faStr3: " << faStr3(testStr3) << std::endl;

    return 0;
}
