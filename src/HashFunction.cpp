#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HashFunction {
public:

  HashFunction(int size, int numHashes1, int numHashes2) {
    this->numHashes1 = numHashes1;
    this->numHashes2 = numHashes2;
    this->size = size;
  }

//getHashes function returns a vector of values after hashing the key
  vector<int> getHashes(string key) {
    vector<int> hashes;
    hash<string> hashString1;
    hash<string> hashString2;
    hash<size_t> hashNumber;

    size_t hashValue = hashString1(key);

    // first hash function
    for (int i=1; i< numHashes1; i++) {
        size_t hashValue = hashNumber(hashValue);   
    }
    //pushing the value modulu the size of the array
    hashes.push_back(hashValue%size);

    //second hash function
    if (numHashes2 > 0) {
      hashValue = hashString2(key);
      for (int i=1; i< numHashes2; i++) {
        size_t hashValue = hashNumber(hashValue);   
      }
    }
    //pushing the value modulu the size of the array
    hashes.push_back(hashValue%size);
    return hashes;
  }

  private:
    int numHashes1;
    int numHashes2;
    int size;

};

