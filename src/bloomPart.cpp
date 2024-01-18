#include <iostream> 
#include <sstream>
#include <map>
#include  "BytesArray.cpp"
#include "AddURL.cpp"
#include "CheckURL.cpp"
#include "URLlist.cpp"
#include "HashFunction.cpp"

using namespace std; 
class BloomPart{
    private:
        map<string, ICommand*> commands;
    public:
        BloomPart(map<string, ICommand*> commands, int[] arr) : commands(commands){}
        void run(){
        string num;
        string url;
        string line;
        int size= arr[0];
        BytesArray bArr(size);
        URLlist urls= URLlist();
        HashFunction hashFunc= HashFunction(size, arr[1],arr[2])
        while(true){
            getline(cin,line);
            istringstream ss(line);
            ss >> num >> url;
            cout << num;
            cout <<url;
            commands[num]->execute();
        }
    

}

        
};
int* inputArr(){
        int num;
        string line;
        getline(cin,line);
        int count = 0;
        istringstream iss(line);
        int* arr= new int[3];
        while (iss >> num)  {
            arr[count] = num;
            count++;
            if(count==3){
                break;
            }

        }
        if(arr[0]==0 || arr[1]== 0){
            cin.clear();
            cout << "wrong input";
            arr= inputArr();
        }
      
        
        return arr;
}

int main(){
    int* arr= inputArr();
    cout << arr[0] << arr[1] <<arr[2];
    map<string, ICommand*> commands;
    ICommand* addU = new AddURL();
    commands["1"]= addU;
    ICommand* checkU = new CheckURL();
    commands["2"]=checkU;
    BloomPart* bp = new BloomPart(commands, arr);
    bp->run();

    return 0;
}