#ifndef NODE_H
#define NODE_H

#include<cstddef>
#include <string>

class Node{
private:
    std::string id;
    std::string data;
    Node* next;

public:
    Node(std::string Data, std::string ID);
    std::string getData();
    void setData(std::string Data);
    std::string getID();
    void setID(std::string ID);
    Node* getNext();
    void setNext(Node* node);
};

#endif