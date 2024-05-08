#include <iostream>
#include <sstream>
#include <map>
#include "BytesArray.h"
#include "AddURL.h"
#include "CheckURL.h"
#include "URLlist.h"
#include "HashFunction.h"
#include "BloomPart.h"
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <thread>
using namespace std;

//constructor
BloomPart::BloomPart(map<string, ICommand*> commands, int arr[])
        : commands(commands), arr(arr), bArr(arr[0]), hashFunc(arr[0], arr[1], arr[2]), urls(){}

void BloomPart::run(int client_sock) {
    char buffer[4096];

    // Endless loop to add/check URLs
    while (true) {
        
        int read_bytes = recv(client_sock, buffer, sizeof(buffer), 0);
                        // cout << "Received message from client: " << read_bytes << endl;

        if (read_bytes == 0) {
            // Connection is closed
          close(client_sock);
            return;
        } else if (read_bytes < 0) {
            // Error
            close(client_sock);
            return;
        } else {
            // Parse the received string
            buffer[read_bytes] = '\0'; // Null-terminate the received data
            string line(buffer); // Convert buffer to string
            istringstream ss(line);
            string num, url;
            ss >> num >> url;
            // cout << "Received message from client: " << endl;

            if (num == "1" || num == "2") {
                        cout << "Received message from client: " << buffer << endl;
                        // cout << "Received url from client: " << url << endl;


                // Invoke the appropriate command based on the parsed command number
                commands[num]->execute(bArr, &urls, url, hashFunc,client_sock);
            }
        }
          close(client_sock);
    }
}


void BloomPart::check(string url,int client_sock)
{
    commands["2"]->execute(bArr,&urls,std::move(url),hashFunc,client_sock);
}
void BloomPart::add(string url,int client_sock)
{
    commands["1"]->execute(bArr,&urls,std::move(url),hashFunc,client_sock);
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