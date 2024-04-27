#include "InputArr.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

InputArr::InputArr() {}

int *InputArr::inputCheck() {
    bool isValidInput = true; // Boolean flag to indicate if input is valid
    int num;
    string token;
    string line;
    int* arr = new int[3];

    do {
        // cout << "Enter input: "; // Prompt the user for input
        getline(cin, line);

        isValidInput = true; // Reset the flag for each iteration

        istringstream iss(line);
        vector<int> integer_array;

        // Step 3 and 4: Check if each element is an integer and add to the array

        // Check that each token in the input is an integer
        while (iss >> token) {
            istringstream tokenStream(token);
            for (char c : token) {
                if (!isdigit(c)) {
                    isValidInput = false;
                    // cout << "Invalid input: Non-integer character detected." << endl;
                    break;
                }
            }
            if (isValidInput && (tokenStream >> num)) {
                integer_array.push_back(num);
            } else {
                isValidInput = false;
                // cout << "Invalid input: Cannot convert token to integer." << endl;
                break;
            }
        }

        // If the input is not valid, prompt for new input
        if (!isValidInput) {
            continue; // Skip the rest of the loop and prompt for new input
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
            // cout << "Invalid input: First number cannot be zero." << endl;
            continue;
        }

        // Check validity (if needed) for input number 2 in the line
        if (arr[1] != 1 && arr[1] != 2) {
            isValidInput = false;
            // cout << "Invalid input: Second number must be 1 or 2." << endl;
            continue;
        }

        // Check validity (if needed) for input number 3 in the line
        if (arr[2] != 0 && arr[2] != 1 && arr[2] != 2) {
            isValidInput = false;
            // cout << "Invalid input: Third number must be 0, 1, or 2." << endl;
            continue;
        }

    } while (!isValidInput); // Repeat the loop until a valid input is obtained

    return arr;
}
