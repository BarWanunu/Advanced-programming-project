#include "AddURL.h"
#include <vector>
using namespace std;
// Constructor implementation
AddURL::AddURL() {
    // Implementation (if any)
}

// Member function implementation
void AddURL::execute(BytesArray arr, URLlist list, std::string url, HashFunction hash) {
    // insert the url to the url list
    list.insertAtBeginning(url);

    // receiving a vector that contains the address of bytes we need to change
    std::vector<int> hashes = hash.getHashes(url);
    for (int i = 0; i < hashes.size(); i++) {
        // changing the bytes in the array
        arr.changeIndex(hashes[i]);
    }
}

