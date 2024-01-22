#include <iostream>
#include <sstream>
#include <map>
#include "BytesArray.h"
#include "AddURL.h"
#include "CheckURL.h"
#include "URLlist.h"
#include "HashFunction.h"
#include "BloomPart.h"

using namespace std;

BloomPart::BloomPart(map<string, ICommand*> commands, int arr[]) : commands(commands), arr(arr){}

void BloomPart::run(){
    string num;
    string url;
    string line;
    //int size = arr[0];
    BytesArray bArr(arr[0]);
    URLlist urls= URLlist();
    HashFunction hashFunc= HashFunction(arr[0], arr[1],arr[2]);
    while(true){
        getline(cin,line);
        istringstream ss(line);
        ss >> num >> url;
            commands[num]->execute(bArr,&urls,url,hashFunc);
    }
}