#ifndef ADDURL_H
#define ADDURL_H

#include "ICommand.h"
#include "BytesArray.h"
#include "URLlist.h"
#include "HashFunction.h"
#include <string>

class AddURL : public ICommand {
public:
    // Constructor declaration
    AddURL();

    // Member function declaration
    void execute(BytesArray arr, URLlist* list, std::string url, HashFunction
    hash);
};

#endif // ADDURL_H
