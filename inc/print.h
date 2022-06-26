#pragma once
#include <iostream>
#include <bitset>

// print
#define p(str) std::cout << str

// print line
#define pl(str) std::cout << str << "\n"

// print and flush buffer
#define pf(str) std::cout << str << std::endl

void printBuffer(std::bitset<8>& flags, char* fileBuffer, size_t fileBuffSz);