#include <iostream>

using namespace std;

class BytesArray {
    private:
     int size;
    public:
    int *byteArr;
    //constructor for the size of the array
    BytesArray(int n) : size(n), byteArr(new int[n]) {
        for (int i = 0; i < size; i++) {
            byteArr[i] = 0;
        }
    }

    //check if the asked index is 1 or 0
    bool checkIfIn(int index){
        if (byteArr[index] == 1){
            return true;
        }
        return false;
    }

    //change the bytes in the array if needed (after the user entered the url)
    void changeIndex (int index1, int index2){
        if (byteArr[index1] == 0){
            byteArr[index1] == 1;
        }
        if (byteArr[index2] == 0 && index2!=-1){
            byteArr[index2] == 1;
        }
    }

    // Function to display the elements of the array
    void display() {
        for (int i = 0; i < size; i++) {
            cout << byteArr[i] << " ";
        }
        cout << endl;
    }
};

int main1(){
    return 0;
}



