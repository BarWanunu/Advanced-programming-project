#include <iostream> 
#include <sstream>
using namespace std; 

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
    return 0;
}