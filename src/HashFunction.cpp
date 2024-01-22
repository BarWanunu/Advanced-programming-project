#include <iostream>
#include <string>
#include <vector>
#include "HashFunction.h"


using namespace std;

HashFunction::HashFunction(int size, int numHashes1, int numHashes2) {
    this->numHashes1 = numHashes1;
    this->numHashes2 = numHashes2;
    this->size = size;
}

vector<int> HashFunction::getHashes(string key) {
    vector<int> hashes;
    hash<string> hashString;

    // first hash to declare it outside the for scopes
    size_t hashValue = hashString(key);
    string value = to_string(hashValue);

    // first hash function
    for (int i = 1; i < numHashes1; i++) {
        hashValue = hashString(value);
        value = to_string(hashValue);
    }
    //pushing the value modulu the size of the array
    hashes.push_back(hashValue % size);

    //second hash function
    if (numHashes2 > 0) {
        for (int i = 0; i < numHashes2; i++) {
            hashValue = hashString(value);
            value = to_string(hashValue);
        }
        //pushing the value modulu the size of the array
        hashes.push_back(hashValue % size);
    }
    return hashes;
}



