
//class for every new URL adress that the user entered
class Node 
public :
    string urlAdress;  
    Node *next; 
    

    //constructor
    Node(String url){
       urlAdress = url;
       next = nullptr;
    }


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
    void insertAtBeginning(int value) {
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
    }

    // Function to check if a value exists in the linked list
    bool contains(String url) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data.compare(url)) {
                return true; 
            }
            current = current->next;
        }
        return false;
    }
}