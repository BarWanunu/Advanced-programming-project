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
    hash<string> hashString1;
    hash<string> hashString2;

    size_t hashValue;
    string value;

    // first hash function
    for (int i = 0; i < numHashes1; i++) {
        hashValue = hashString1(key);
        value = to_string(hashValue);
    }
    //pushing the value modulu the size of the array
    hashes.push_back(hashValue % size);

    /*
     * a case when the functions will make the same number of hashes on the
     * key, we can return the vector because the values will be the same
    */
     if (numHashes1 == numHashes2) {
        return hashes;
    }
    //second hash function
    if (numHashes2 > 0) {
        for (int i = 0; i < numHashes2; i++) {
            hashValue = hashString2(key);
            value = to_string(hashValue);
        }
        //pushing the value modulu the size of the array
        hashes.push_back(hashValue % size);
    }
    return hashes;
}



