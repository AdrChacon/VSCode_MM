#include "LinkedList.h"
#include<iostream>
//constructor
LinkedList::LinkedList(){
    size = 0;
    head = NULL;
}
//Retorna cabeza lista
Node* LinkedList::getHead(){
    return head;
}
//mete un nodo en la lista
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
//obtiene un nodo
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
//remueve un nodo
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
//ve si esta vacia la lista
bool LinkedList::isEmpty(){
    return size==0;
}
//tiene el tamano de la lista
int LinkedList::getSize(){
    return size;
}
//imprime cada nodo de la lista
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
//cambia la data de un nodo de la lista
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
//obtiene la data de un nodo de la lista
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
