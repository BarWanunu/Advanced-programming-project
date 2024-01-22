#include "BytesArray.h"
#include <iostream>

// Constructor implementation
BytesArray::BytesArray(int n) : size(n), byteArr(new int[n]) {
    for (int i = 0; i < size; i++) {
        byteArr[i] = 0;
    }
}

bool BytesArray::checkIfIn(int index) {
    bool x = byteArr[index] == 1;
    return x;
}

void BytesArray::changeIndex(int index) {
    if (byteArr[index] == 0) {
        byteArr[index] = 1;
    }
}

void BytesArray::display() {
    for (int i = 0; i < size; i++) {
        std::cout << byteArr[i] << " ";
    }
    std::cout << std::endl;
}
