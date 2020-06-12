#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<cstddef>
#include "Node.h"
using namespace std;


class LinkedList{
private:
    Node* head;
    int size;
public:
    LinkedList();
    Node* getHead();
    int getSize();
    void addNode(std::string data, std::string id);
    Node* getNode(std::string id);
    void removeNode(std::string id);
    bool isEmpty();
    void printList();

    void change_data(std::string id, std::string data);
    std::string obtencion(std::string id);
};
#endif