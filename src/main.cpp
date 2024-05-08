#include <sstream>
#include <map>
#include "AddURL.h"
#include "BloomPart.h"
#include "CheckURL.h"
#include "ICommand.h"
#include "Node.h"
#include "URLlist.h"
#include "InputArr.h"
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <thread>
using namespace std;
BloomPart* bp;

// Define a helper function to print the contents of the array
void printArray(int* arr) {
    std::cout << "Array contents: ";
    for (int i = 0; i < 3; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

map<string, ICommand*> inputCommands(){
    map<string, ICommand*> commands;
    ICommand* addU = new AddURL();
    commands["1"]= addU;
    ICommand* checkU = new CheckURL();
    commands["2"]=checkU;
    return commands;
}
// Function to handle client requests
void handleClient(int client_sock) {
    char buffer[4096];
    // int arr[3];

     if (!bp) {
    InputArr* inputArr = new InputArr();
    int* arr = inputArr->inputCheck(client_sock);

    // Now you have the arr data and can use it
    // Initialize BloomPart instance with received arr
    map<string, ICommand*> commands = inputCommands();
    bp = new BloomPart(commands, arr);

    // Proceed with handling other client requests
    cout << "Received arr from client: " << arr[0] << ", " << arr[1] << ", " << arr[2] << endl;
     }
        //  cout << "Received arr from client: " << bp->size() << endl;
// 
    // Run BloomPart with the received arr
    bp->run(client_sock);

    close(client_sock);
}


int main() {
    const int server_port = 5555;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        perror("error creating socket");
        return 1;
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    if (bind(sock, (struct sockaddr*)&sin, sizeof(sin)) < 0) {
        perror("error binding socket");
        return 1;
    }

    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
        return 1;
    }

  
    while (true) {
        //  cout << "Received message from client:3 " << endl;
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr*)&client_sin, &addr_len);

        if (client_sock < 0) {
            perror("error acceptisng client");
            continue;
        }

        // Create a new thread to handle communication with the client
        thread client_thread(handleClient, client_sock);
        client_thread.detach(); // Detach the thread to run independently
    }

    close(sock);
    
    return 0;
}
