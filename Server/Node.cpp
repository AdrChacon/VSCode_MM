#include "Node.h"


Node::Node(std::string Data, std::string ID){
    id = ID;
    data = Data;
    next = NULL;
}


std::string Node::getData(){
    return data;
}

void Node::setID(std::string ID){
    id = ID;
}

std::string Node::getID(){
    return id;
}

void Node::setData(std::string Data){
    data = Data;
}

Node* Node::getNext(){
    return next;
}

void Node::setNext(Node* node){
    next = node;
}