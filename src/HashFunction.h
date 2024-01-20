#ifndef HASHFUNCTION_H
#define HASHFUNCTION_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class HashFunction {
public:
    HashFunction(int size, int numHashes1, int numHashes2);
    vector<int> getHashes(string key);

private:
    int numHashes1;
    int numHashes2;
    int size;
};

#endif // HASHFUNCTION_H
