#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <string>
#include "URLlist.h"
#include "HashFunction.h"
#include "BytesArray.h"

class ICommand {
public:
    virtual void execute(BytesArray arr, URLlist* list, std::string url,
                         HashFunction hash,int client_sock) = 0;
};

#endif // ICOMMAND_H
