#include <sstream>
#include <map>
#include "AddURL.h"
#include "BloomPart.h"
#include "CheckURL.h"
#include "ICommand.h"
#include "Node.h"
#include "URLlist.h"
#include "InputArr.h"

map<string, ICommand*> inputCommands(){
    map<string, ICommand*> commands;
    ICommand* addU = new AddURL();
    commands["1"]= addU;
    ICommand* checkU = new CheckURL();
    commands["2"]=checkU;
    return commands;
}

int main(){
    InputArr* inputArr = new InputArr();
    int* arr = inputArr->inputCheck();
    map<string, ICommand*> commands = inputCommands();
    BloomPart* bp = new BloomPart(commands, arr);
    bp->run();

    delete inputArr;
    delete bp;

    delete[] arr;

    return 0;
}