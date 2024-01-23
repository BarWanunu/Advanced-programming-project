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
    string token;
    string line;
    getline(cin,line);
    int count = 0;

    istringstream iss(line);
    int* arr=  new int[3];
    vector<int> integer_array;


    // Step 3 and 4: Check if each element is an integer and add to the array

    //check that there is no strings in the input
    while (iss >> token) {
        istringstream tokenStream(token);
        for (char c : token) {
            if (!isdigit(c)) {
                cin.clear();
                return inputArr();
            }
        }
        if (tokenStream >> num) {
            integer_array.push_back(num);
        } else {
            cin.clear();
            return inputArr();
        }
    }

    //reset the array
    for(int i =0;i<3;i++){
        arr[i]=0;
    }

    //check validity of input
    for(int i : integer_array)  {
        arr[count] = i;
        count++;
        if(count==3){
            break;
        }

    }

    //check validity (if needed) for input number 1 in the line
    if(arr[0]==0){
        cin.clear();
        return inputArr();

    }

    //check validity (if needed) for input number 2 in the line
    if(arr[1]!=1){
        if(arr[1]!=2){
            cin.clear();
            return inputArr();
        }
    }

    //check validity (if needed) for input number 3 in the line
    if(arr[2]!=0){
        if(arr[2]!=1&&arr[2]!=2){
            cin.clear();
            return inputArr();
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