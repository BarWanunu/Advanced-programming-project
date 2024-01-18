#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HashFunction {
public:

  HashFunction(string key, int numHashes) {
    this->key = key;
    this->numHashes = numHashes;
  }

  int getHashes() {
    hash<string> hashString;
    hash<size_t> hashNumber;

    size_t hashValue = hashString(key);

    for (int i=1; i< numHashes; i++) {
        size_t hashValue = hashNumber(hashValue);   
    }
    return hashValue%8;
  }

  private:
    string key;
    int numHashes;
};