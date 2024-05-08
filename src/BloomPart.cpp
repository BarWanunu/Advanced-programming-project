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

//constructor
BloomPart::BloomPart(map<string, ICommand*> commands, int arr[])
        : commands(commands), arr(arr), bArr(arr[0]), hashFunc(arr[0], arr[1], arr[2]), urls(){}

void BloomPart::run(){
    string num;
    string url;
    string line;

    // endless while loop to add/check url
    while(true){
        getline(cin,line);
        istringstream ss(line);
        ss >> num >> url;
        if(num=="1"||num=="2"){
            commands[num]->execute(bArr,&urls,url,hashFunc);

        }
    }
}

void BloomPart::check(string url)
{
    commands["2"]->execute(bArr,&urls,std::move(url),hashFunc);
}
void BloomPart::add(string url)
{
    commands["1"]->execute(bArr,&urls,std::move(url),hashFunc);
}
int BloomPart::numhashes(){
    return arr[1]+arr[2];
}
int BloomPart::numfunctions(){
    if(arr[2]==0){
        return 1;
    }
    return 2;
}
int BloomPart::size(){
    return arr[0];
}