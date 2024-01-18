#ifndef BYTESARRAY_H
#define BYTESARRAY_H

#include <iostream>

class BytesArray {
private:
    int size;
public:
    int *byteArr;

    // Constructor for the size of the array
    BytesArray(int n);

    // Destructor to free dynamically allocated memory
    ~BytesArray();

    // Check if the asked index is 1 or 0
    bool checkIfIn(int index);

    // Change the specific byte in the array if needed
    void changeIndex(int index);

    // Function to display the elements of the array
    void display();
};

#endif // BYTESARRAY_H
