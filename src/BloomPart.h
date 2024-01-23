#ifndef BLOOMPART_H
#define BLOOMPART_H
#include "BytesArray.h"
#include "HashFunction.h"
#include "URLlist.h"
#include "ICommand.h"


class BloomPart{
private:
    map<string, ICommand*> commands;
    int* arr;
    URLlist urls;
    HashFunction hashFunc;
    BytesArray bArr;

public:
    BloomPart(map<string, ICommand*> commands, int arr[]); // Constructor declaration
    void run();
    void check(string url);
    void add(string url);
    int numhashes();
    int numfunctions();
    int size();
};

#endif // BLOOMPART_H