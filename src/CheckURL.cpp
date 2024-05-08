#include <iostream>
#include <string>
#include <vector>
#include "CheckURL.h"
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <thread>
using namespace std;


CheckURL::CheckURL() {
    // Constructor implementation (if any)
}

void CheckURL::execute(BytesArray arr, URLlist* list, std::string url, HashFunction hash, int client_sock) {
    //vector of 1 or 2 indexes
    vector<int> indexVector = hash.getHashes(url);
    for (int i = 0; i < indexVector.size(); i++) {
        //check if the byte is 1
        if (arr.checkIfIn(indexVector[i])) {
            if (i == 0 && indexVector.size() != 1) {
                continue;
            }
            //if the byte is 1 check if the url is in the list
            if (list->contains(url)) {
                string message = "true true";
                send(client_sock, message.c_str(), message.length(), 0);
                return;
            }
            string message = "true false";
            send(client_sock, message.c_str(), message.length(), 0);
            return;
        }
    }
    string message = "false";
    send(client_sock, message.c_str(), message.length(), 0);
}
