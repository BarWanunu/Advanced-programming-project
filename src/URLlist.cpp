#include <iostream>
#include <string>
#include "Node.h"
#include "URLlist.h"
using namespace std;


URLlist::URLlist(){
    this->head = nullptr;
}

//adding the url address to the list
void URLlist::insertAtBeginning(const string& url){
    Node* newNode = new Node(url);
    newNode->next = head;
    head = newNode;
}
void URLlist::display(){
    Node* current = head;
    while (current != nullptr) {
        cout << current->urlAdress << "\n";
        current = current->next;

        cout << endl;
    }
}

//checking if the url adress is in the list
bool URLlist::contains(const string& url){

    Node* current = head;
    while (current != nullptr) {
        if (current->urlAdress.compare(url) == 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}