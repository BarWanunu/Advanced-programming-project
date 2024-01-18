#include "ICommand.cpp"
#include "BytesArray.cpp"
#include "URLlist.cpp"
#include "HashFunction.cpp"

using namespace std;

class AddURL:public ICommand{
    public:
    //empty constructor
        AddURL();
        void execute(BytesArray arr, URLlist list, string url, HashFunction hash) {
        // insert the url to the url list
         list.insertAtBeginning(url);
            // receiving a vector that contains the address of bytes we need to change
            vector<int> hashes = hash.getHashes(url);
            for (int i=0; i<hashes.size(); i++) {
                // changing the bytes in the array
                arr.changeIndex(hashes[i]);
            }   
    }
};