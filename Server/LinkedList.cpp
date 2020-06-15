#include "LinkedList.h"
#include<iostream>

/**
 * Constructor
 */
LinkedList::LinkedList(){
    size = 0;
    head = NULL;
}

/**
 * Retorna la cabeza de la lista
 * @return Node
 */
Node* LinkedList::getHead(){
    return head;
}

/**
 * Agrega un nodo a la lista
 * @param data
 * @param id
 */
void LinkedList::addNode(std::string data,std::string id){
    Node* node = new Node(data,id);
    if (isEmpty()){
        head = node;
        size++;
    } else {
        Node* current = getHead();
        while(current->getNext() != NULL){
            current = current->getNext();
        }
        current->setNext(node);
        size++;
    }
}

/**
 * Obtiene un nodo
 * @return Node
 */
Node* LinkedList::getNode(std::string id){
    Node* current = getHead();
    while(current->getNext() != NULL){
        if (current->getData() == id){
            return current;
        } else {
            current = current->getNext();
        }
    }
    return NULL;
}

/**
 * Remueve un nodo de la lista
 * @param id
 */
void LinkedList::removeNode(std::string id){
    Node* current = getHead();
    if (current->getData() == id){
        head = current->getNext();
    } else {
        while(current->getNext() != NULL){
            if(current->getNext()->getData() == id){
                current->setNext(current->getNext()->getNext());
                size--;
            } else {
                current = current->getNext();
            }
            
        }
        
    }
}

/**
 * Verifica si la lista esta vacia
 * @return bool
 */
bool LinkedList::isEmpty(){
    return size==0;
}

/** 
 * Obtiene el largo de la lista
 * @return int
 */
int LinkedList::getSize(){
    return size;
}

/**
 * Imprime cada nodo de la lista
 */
void LinkedList::printList(){
    if(!isEmpty()){
        cout << "La lista posee:" << endl;
        Node* current = getHead();
        for(int i = 0; i < size; i++){
            printf("El nodo %d:\n",i);
            cout <<"ID " + current->getID() << endl;
            cout <<"Dato " + current->getData() << endl;
            current = current->getNext();
        }
    } else {
        cout << "List is empty." << endl;
    }
}

/**
 * Cambia los datos de un nodo de la lista
 * @param id
 * @param data
 */
void LinkedList::change_data(std::string id, std::string data) {
    Node* current = getHead();
    while(current != NULL){
        if (current->getID() == id){
            current -> setData(data);
            break;
        } else {
            current = current->getNext();
        }
    }


}

/**
 * Obtiene los datos de un nodo de la lista
 * @param id
 * @return string
 */
std::string LinkedList::obtencion(std::string id) {
    Node* current = getHead();
    while(current != NULL){
        if (current->getID() == id){
           return current -> getData();
        } else {
            current = current->getNext();
        }
    }


}
