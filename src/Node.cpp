#include "Node.h"

Node::Node(std::string url) : urlAdress(url), next(nullptr) {
    urlAdress = url;
    next = nullptr;
}
