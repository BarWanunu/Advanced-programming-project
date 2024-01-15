#include <iostream> 
using namespace std; 
#include <sstream>

int* inputArr(){
        int size;
        string line;
        getline(cin,line);
        int count = 0;
        istringstream iss(line);
        int* arr= new int[3];
        while (iss >> size)  {
            arr[count] = size;
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


    return 0;
}