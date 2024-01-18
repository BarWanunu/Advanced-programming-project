#include <iostream>
#include <string>
#include <vector>
#include "HashFunction.cpp"
#include "ICommand.cpp"
#include "BytesArray.cpp"
#include "URLlist.cpp"

using namespace std;

class CheckURL:public ICommand{
    public :
        CheckURL();
        void execute(BytesArray arr, URLlist list, string url, HashFunction hash){
            //vector of 1 or 2 insexes
            vector<int> indexVector=hash.getHashes(url);
            for (int i=0; i<indexVector.size(); i++){
                //check if the byte is 1
                if (arr.checkIfIn(indexVector[i])){
                    //if the byte is 1 check if the url is in the list
                    if (list.contains(url)){
                        cout << "true true" << endl;
                        continue;
                    }
                    cout << "true false" << endl;
                    continue;
                }
                cout << "false" << endl;
            }
        }
};