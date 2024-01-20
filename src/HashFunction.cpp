#include <iostream>
#include <string>
#include <vector>
#include "HashFunction.h"


using namespace std;

HashFunction::HashFunction(int size, int numHashes1, int numHashes2){
    this->numHashes1 = numHashes1;
    this->numHashes2 = numHashes2;
    this->size = size;
}
vector<int> HashFunction::getHashes(string key){
      vector<int> hashes;
    hash<string> hashString1;
    hash<string> hashString2;
    hash<int> hashNumber1;
    hash<int> hashNumber2;

    int hashValue = hashString1(key);

    // first hash function
    for (int i=1; i< numHashes1; i++) {
        hashValue = hashNumber1(hashValue);   
    }
    //pushing the value modulu the size of the array
    cout << hashValue << endl;
    hashes.push_back(hashValue%size);

    //second hash function
    if (numHashes2 > 0) {
      hashValue = hashString2(key);
      for (int i=1; i< numHashes2; i++) {
        hashValue = hashNumber2(hashValue);   
      }
      //pushing the value modulu the size of the array
      hashes.push_back(hashValue%size);
    }
   
    return hashes;
  
}



