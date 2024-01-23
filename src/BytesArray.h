#ifndef BYTESARRAY_H
#define BYTESARRAY_H

class BytesArray {
private:
    int size;
    int* byteArr;

public:
    BytesArray(int n);  // Constructor declaration
    bool checkIfIn(int index);
    void changeIndex(int index);
    void display();

};

#endif // BYTESARRAY_H
