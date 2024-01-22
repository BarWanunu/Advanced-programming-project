#include <iostream>
#include <string>
#include <vector>

using namespace std;
#include "CheckURL.h"


CheckURL::CheckURL() {
    // Constructor implementation (if any)
}

void CheckURL::execute(BytesArray arr, URLlist* list, std::string url,
                       HashFunction hash) {
    //vector of 1 or 2 insexes
    vector<int> indexVector=hash.getHashes(url);
    for (int i=0; i<indexVector.size(); i++){
        //check if the byte is 1
        if (arr.checkIfIn(indexVector[i])){
            if (i == 0) {
                continue;
            }
            //if the byte is 1 check if the url is in the list
            if (list->contains(url)){
                cout << "true true" << endl;
                break;
            }
            cout << "true false" << endl;
            break;
        }
        cout << "false" << endl;
        break;
    }
}
