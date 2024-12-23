#include <exception>
#include "SetIterator.h"
#include "Set.h"


SetIterator::SetIterator(Set& m) : set(m)
{
    this->node=this->set.head;
}
//Theta(1)


void SetIterator::first() {
    this->node=this->set.head;
}
//Theta(1)


TElem SetIterator::remove() {
    TElem elem = getCurrent();

    if (node == set.head) {
        Node *temp = node;
        node = node->next;
        delete temp;
        set.head = node;
        set._size--;
    } else {
        Node *prev = set.head;
        while (prev->next != node) {
            prev = prev->next;
        }
        prev->next = node->next;
        delete node;
        node = prev->next;
        set._size--;
    }
    if (!valid())
        throw std::exception();
    return elem;
}



void SetIterator::next() {
    if(this->node== nullptr)
        throw std::exception();
    this->node=this->node->next;
}
//Theta(1)



TElem SetIterator::getCurrent()
{
    if(!this->valid())
        throw std::exception();
    return this->node->elem;
    //return NULL_TELEM;
}
//Theta(1)


bool SetIterator::valid() const {
    if(this->node!= nullptr)
        return true;
    return false;
}
//Theta(1)



