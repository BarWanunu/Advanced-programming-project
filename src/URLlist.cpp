#include <iostream>

using namespace std;

//class for every new URL adress that the user entered
class Node {
public :
    string urlAdress;  
    Node *next; 
    

    //constructor
    Node(string url){
       urlAdress = url;
       next = nullptr;
    }
};

// class to intialize the linked list 
class LinkedList {  
    private:  
    Node *head;  
    
    public:  
    //constructor
    LinkedList() {  
        this->head = nullptr;  
    }  

    //insert URL adress
    void insertAtBeginning(const string& url /*, BytesArray arr*/) {
            Node* newNode = new Node(url);
            newNode->next = head;
            head = newNode;
            /*
            -------hash function that gives us index 1 and index 2-------
            arr.insertURL(index 1, index 2);
            */
    }

    // Function to display the elements of the linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->urlAdress << "\n";
            current = current->next;
        }
        cout << endl;
    }

    // Function to check if a value exists in the linked list
    bool contains(const string& url) {
        Node* current = head;
        while (current != nullptr) {
            if (current->urlAdress.compare(url)) {
                return true; 
            }
            current = current->next;
        }
        return false;
    }
};

int main() {
    LinkedList myList;
    myList.insertAtBeginning("www.example.com0" /*, arr*/);
    myList.insertAtBeginning("www.example.com1" /*, arr*/);
    myList.insertAtBeginning("www.example.com7" /*, arr*/);
    myList.display();
	return 0;
    
}