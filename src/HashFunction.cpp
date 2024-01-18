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

  std::vector<size_t> getHashes() {
    std::hash<string> hashString;
    std::vector<size_t> hashes;

    size_t hashValue = hashString(key);

    for (int i=1; i< numHashes; i++) {
        size_t hashValue = hashString(key);   
    }
    hashes.push_back(hashValue%8);
    return hashes;
  }

  private:
    string key;
    int numHashes;
};