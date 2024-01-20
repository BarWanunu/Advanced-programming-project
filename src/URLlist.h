

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

#ifndef URLLIST_H
#define URLLIST_H
class URLlist {
private:
    Node* head;

public:
    // Constructor
    URLlist();

    // Member functions
    void insertAtBeginning(const string& url);
    void display();
    bool contains(const string& url);
};

#endif // URLLIST_H
