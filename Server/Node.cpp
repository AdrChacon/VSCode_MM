#include "Node.h"

/**
 * Constructor
 */
Node::Node(std::string Data, std::string ID){
    id = ID;
    data = Data;
    next = NULL;
}

/**
 * Obtiene el dato del nodo
 * @return Dato
 */
std::string Node::getData(){
    return data;
}

/**
 * Establece el ID del nodo
 */
void Node::setID(std::string ID){
    id = ID;
}

/**
 * Retorna el id del nodo
 */
std::string Node::getID(){
    return id;
}

/**
 * Establece el dato del nodo
 */
void Node::setData(std::string Data){
    data = Data;
}

/**
 * Obtiene el siguiente nodo
 * @return Node
 */
Node* Node::getNext(){
    return next;
}

/** Establece el siguiente nodo
 *  @param node
 */
void Node::setNext(Node* node){
    next = node;
}