#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
public:
    std::string urlAdress;
    Node* next;

    Node(std::string url);
};

#endif // NODE_H
