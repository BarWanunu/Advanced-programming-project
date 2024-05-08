#ifndef CHECKURL_H
#define CHECKURL_H

#include <string>
#include "ICommand.h"  // Include the correct header file for ICommand
#include "BytesArray.h"
#include "URLlist.h"
#include "HashFunction.h"

class CheckURL : public ICommand {
public:
    CheckURL();  // Constructor declaration
    void execute(BytesArray arr, URLlist* list, std::string url, HashFunction
    hash) override;
};

#endif // CHECKURL_H
