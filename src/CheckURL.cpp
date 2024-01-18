#include "Icommand.cpp"
#include "BytesArray.cpp"
#include "URLlist.cpp"
#include "bloomPart.cpp"

using namespace std;

class CheckURL:public ICommand{
    public :
        void execute(BytesArray arr, URLlist list, String url, HashFunction hash){
            //vector of 1 or 2 insexes
            vector<int> indexVector=hash.getHashes(url);
            for (int i=0; i<indexVector.size(); i++){
                //check if the byte is 1
                if (arr.checkIfIn(indexVector[i])){
                    //if the byte is 1 chekc if the url is in the list
                    if (list.contains(url)){
                        cout << "true true"
                        continue;
                    }
                    cout << "true false"
                    continue;
                }
                cout << "false";
            }
        }

};

int main(){
    return 0;
}