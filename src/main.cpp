#include "BytesArray.cpp"
#include "URLlist.cpp"


int main() {
    LinkedList myList;
    BytesArray arr(8);
    myList.insertAtBeginning("www.example.com0");
    /*----hash function that gives us index----
    arr.changeIndex(index 1, index 2);
    */
    myList.insertAtBeginning("www.example.com1");
    /*----hash function that gives us index----
    arr.changeIndex(index 1, index 2);
    */
    myList.insertAtBeginning("www.example.com7");
    /*----hash function that gives us index----
    arr.changeIndex(index);
    */
    myList.display();
    arr.display();
    
	return 0;
}