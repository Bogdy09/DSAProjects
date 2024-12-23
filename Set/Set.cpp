#include "Set.h"
#include "SetITerator.h"

Set::Set() {
    this->head= nullptr;
    this->_size=0;

}


Node* Set::get_last(){
    if(this->head== nullptr)
        return nullptr;
    Node* current=this->head;
    while(current->next!= nullptr)
        current=current->next;
    return current;
}
//BC=Theta(1) WC=Theta(n) AC=O(n)

bool Set::add(TElem elem) {
    if(this->search(elem))
        return false;
    Node* last=get_last();
    Node* new_node=new Node;
    new_node->elem=elem;
    new_node->next= nullptr;
    if(last== nullptr)
        this->head=new_node;
    else
    {
        last->next=new_node;
    }
    this->_size++;
    return true;
}
//BC=Theta(1) WC=Theta(n) AC=O(n)

bool Set::remove(TElem elem) {
    if(!search(elem))
        return false;
    if(this->head->elem==elem){
        Node* node=this->head;
        this->head=this->head->next;
        delete node;
        this->_size--;
        return true;
    }
    Node* node=this->head;
    while(node!= nullptr) {
        if (node->next->elem == elem) {
            Node *current = node->next;
            node->next = node->next->next;
            delete current;
            this->_size--;
            return true;
        }
        node=node->next;
    }
    return false;
}
//BC=Theta(1) WC=Theta(n) AC=O(n)

bool Set::search(TElem elem) const {
    Node* node=this->head;
    while(node!= nullptr){
        if(node->elem==elem)
            return true;
        node=node->next;
    }
    return false;
}
//BC=Theta(n) WC=Theta(1) AC=O(n)


int Set::size() const {
    return this->_size;
}
//Theta(1)


bool Set::isEmpty() const {
    if(size()==0)
        return true;
    return false;
}
//Theta(1)


Set::~Set() {
    Node* node=this->head;
    while(node!= nullptr){
        Node* current=node->next;
        delete node;
        node=current;
    }
}
//BC=Theta(n) WC=Theta(1) AC=O(n)

SetIterator Set::iterator() {
    return SetIterator(*this);
}
//Theta(1)


