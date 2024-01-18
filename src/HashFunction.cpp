#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HashFunction {
public:

  HashFunction(int numHashes1, int numHashes2, int size) {
    this->numHashes1 = numHashes1;
    this->numHashes2 = numHashes2;
    this->size = size;
  }

  vector<int> getHashes(string key) {
    vector<int> hashes;
    hash<string> hashString1;
    hash<string> hashString2;
    hash<size_t> hashNumber;

    size_t hashValue = hashString1(key);

    for (int i=1; i< numHashes1; i++) {
        size_t hashValue = hashNumber(hashValue);   
    }
    hashes.push_back(hashValue%size);
    if (numHashes2 > 0) {
      hashValue = hashString2(key);
      for (int i=1; i< numHashes2; i++) {
        size_t hashValue = hashNumber(hashValue);   
      }
    }
    hashes.push_back(hashValue%size);
    return hashes;
  }

  private:
    int numHashes1;
    int numHashes2;
    int size;

};

int main() {
  return 0;
}
