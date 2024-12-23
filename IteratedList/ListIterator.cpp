#include "ListIterator.h"
#include <stdexcept>

ListIterator::ListIterator(const IteratedList& lista) : list(lista), currentIndex(lista.head) {}

void ListIterator::first() {
    currentIndex = list.head;
}

void ListIterator::next() {
    if (!valid()) {
        throw std::out_of_range("Iterator out of bounds");
    }
    currentIndex = list.nodes[currentIndex].next;
}

bool ListIterator::valid() const {
    return currentIndex != NULL_INDEX;
}

TElem ListIterator::getCurrent() const {
    if (!valid()) {
        throw std::out_of_range("Iterator out of bounds");
    }
    return list.nodes[currentIndex].value;
}
