#include <iostream>
#include <sstream>
#include <map>
#include "BytesArray.h"
#include "AddURL.h"
#include "CheckURL.h"
#include "URLlist.h"
#include "HashFunction.h"
#include "BloomPart.h"


int* inputArr(){
    int num;
    string line;
    getline(cin,line);
    int count = 0;

    istringstream iss(line);
    int* arr=  new int[3];
    vector<int> integer_array;

    // Step 3 and 4: Check if each element is an integer and add to the array

    while (iss >> num) {
        integer_array.push_back(num);
    }
    for(int i =0;i<3;i++){
        arr[i]=0;
    }
    for(int i : integer_array)  {
        arr[count] = i;
        count++;
        if(count==3){
            break;
        }

    }
    if(arr[0]==0){
        cin.clear();
        arr= inputArr();

    }
    if(arr[1]!=1){
        if(arr[1]!=2){
            cin.clear();
            arr= inputArr();
        }
    }


    if(arr[2]!=0){
        if(arr[2]!=1&&arr[2]!=2){
            cin.clear();
            arr= inputArr();
        }
    }



    return arr;
}


int main(){
    int* arr= inputArr();
    map<string, ICommand*> commands;
    ICommand* addU = new AddURL();
    commands["1"]= addU;
    ICommand* checkU = new CheckURL();
    commands["2"]=checkU;
    BloomPart* bp = new BloomPart(commands, arr);
    bp->run();

    return 0;
}