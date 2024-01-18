#include "ICommand.cpp"
#include "BytesArray.cpp"
#include "URLlist.cpp"
#include "HashFunction.cpp"

using namespace std;

class AddURL:public ICommand{
    public:
        void execute(BytesArray arr, URLlist list, string url, HashFunction hash) {
         list.insertAtBeginning(url);
            vector<int> hashes = hash.getHashes(url);
            for (int i=0; i<hashes.size(); i++) {
                arr.changeIndex(hashes[i]);
            }   
    }
};

int main() {
    return 0;
}