#include "Node.h"

//constructor
Node::Node(std::string Data, std::string ID){
    id = ID;
    data = Data;
    next = NULL;
}

//tiene la data del nodo
std::string Node::getData(){
    return data;
}
//set id
void Node::setID(std::string ID){
    id = ID;
}
//tiene el id del nodo
std::string Node::getID(){
    return id;
}
//setea la data
void Node::setData(std::string Data){
    data = Data;
}
//obtiene el siguiente nodo
Node* Node::getNext(){
    return next;
}
//setea el siguiente nodo
void Node::setNext(Node* node){
    next = node;
}