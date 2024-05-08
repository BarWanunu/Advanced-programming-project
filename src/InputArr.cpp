#include "InputArr.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <thread>
using namespace std;

InputArr::InputArr() {}

int *InputArr::inputCheck(int client_sock) {
    bool isValidInput = true; // Boolean flag to indicate if input is valid
    int num;
    string token;
    string line;
    int* arr = new int[3];

     do {
        isValidInput = true; // Reset the flag for each iteration

        // Receive input from the server
        char buffer[4096];
        int read_bytes = recv(client_sock, buffer, sizeof(buffer), 0);
            // cout << "Received message : " << buffer << endl;
        if (read_bytes <= 0) {
            // Error or connection closed, handle appropriately
            perror("error receiving input from server");
            delete[] arr;
            return nullptr;
        }

        // Convert received buffer to string
        string input(buffer, read_bytes);

        istringstream iss(input);
        vector<int> integer_array;

        // Step 3 and 4: Check if each element is an integer and add to the array

        // Check that each token in the input is an integer
        while (iss >> token) {
            istringstream tokenStream(token);
            for (char c : token) {
                if (!isdigit(c)) {
                    isValidInput = false;
                    break;
                }
            }
            if (isValidInput && (tokenStream >> num)) {
                integer_array.push_back(num);
            } else {
                isValidInput = false;
                break;
            }
        }

        // If the input is not valid, continue to receive input
        if (!isValidInput) {
            continue;
        }

        // Reset the array
        for (int i = 0; i < 3; i++) {
            arr[i] = 0;
        }

        // Check the validity of input
        int count = 0;
        for (int i : integer_array) {
            arr[count] = i;
            count++;
            if (count == 3) {
                break;
            }
        }

        // Check validity (if needed) for input number 1 in the line
        if (arr[0] == 0) {
            isValidInput = false;
            continue;
        }

        // Check validity (if needed) for input number 2 in the line
        if (arr[1] != 1 && arr[1] != 2) {
            isValidInput = false;
            continue;
        }

        // Check validity (if needed) for input number 3 in the line
        if (arr[2] != 0 && arr[2] != 1 && arr[2] != 2) {
            isValidInput = false;
            continue;
        }

    } while (!isValidInput); // Repeat the loop until a valid input is obtained
    close(client_sock);
    return arr;
}
