#include "IteratedList.h"
#include <stdexcept>

const int NULL_INDEX = -1;
const int INITIAL_CAPACITY = 10;

IteratedList::IteratedList() : capacity(INITIAL_CAPACITY), head(NULL_INDEX), firstEmpty(0), listSize(0) {
    nodes = new Node[capacity];
    for (int i = 0; i < capacity - 1; ++i) {
        nodes[i].next = i + 1;
    }
    nodes[capacity - 1].next = NULL_INDEX;
}

IteratedList::~IteratedList() {
    delete[] nodes;
}

void IteratedList::resize() {
    int newCapacity = capacity * 2;
    Node* newNodes = new Node[newCapacity];

    for (int i = 0; i < capacity; ++i) {
        newNodes[i] = nodes[i];
    }

    for (int i = capacity; i < newCapacity - 1; ++i) {
        newNodes[i].next = i + 1;
    }
    newNodes[newCapacity - 1].next = NULL_INDEX;

    firstEmpty = capacity;
    capacity = newCapacity;
    delete[] nodes;
    nodes = newNodes;
}

int IteratedList::size() const {
    return listSize;
}

bool IteratedList::isEmpty() const {
    return listSize == 0;
}

ListIterator IteratedList::first() const {
    return ListIterator(*this);
}

TElem IteratedList::getElement(ListIterator pos) const {
    if (!pos.valid()) {
        throw std::out_of_range("Invalid iterator position");
    }
    return nodes[pos.currentIndex].value;
}

TElem IteratedList::setElement(ListIterator pos, TElem e) {
    if (!pos.valid()) {
        throw std::out_of_range("Invalid iterator position");
    }
    TElem oldValue = nodes[pos.currentIndex].value;
    nodes[pos.currentIndex].value = e;
    return oldValue;
}

void IteratedList::addToEnd(TElem e) {
    if (firstEmpty == NULL_INDEX) {
        resize();
    }

    int newNode = firstEmpty;
    firstEmpty = nodes[firstEmpty].next;

    nodes[newNode].value = e;
    nodes[newNode].next = NULL_INDEX;

    if (head == NULL_INDEX) {
        head = newNode;
    } else {
        int current = head;
        while (nodes[current].next != NULL_INDEX) {
            current = nodes[current].next;
        }
        nodes[current].next = newNode;
    }

    ++listSize;
}

void IteratedList::addToBeginning(TElem e) {
    if (firstEmpty == NULL_INDEX) {
        resize();
    }

    int newNode = firstEmpty;
    firstEmpty = nodes[firstEmpty].next;

    nodes[newNode].value = e;
    nodes[newNode].next = head;
    head = newNode;

    ++listSize;
}

void IteratedList::addToPosition(ListIterator& pos, TElem e) {
    if (!pos.valid()) {
        throw std::out_of_range("Invalid iterator position");
    }

    if (firstEmpty == NULL_INDEX) {
        resize();
    }

    int newNode = firstEmpty;
    firstEmpty = nodes[firstEmpty].next;

    nodes[newNode].value = e;
    nodes[newNode].next = nodes[pos.currentIndex].next;
    nodes[pos.currentIndex].next = newNode;

    pos.currentIndex = newNode;
    ++listSize;
}

TElem IteratedList::remove(ListIterator& pos) {
    if (!pos.valid()) {
        throw std::out_of_range("Invalid iterator position");
    }

    int toRemove = pos.currentIndex;

    if (toRemove == head) {
        head = nodes[head].next;
    } else {
        int current = head;
        while (nodes[current].next != toRemove) {
            current = nodes[current].next;
        }
        nodes[current].next = nodes[toRemove].next;
    }

    pos.currentIndex = nodes[toRemove].next;
    nodes[toRemove].next = firstEmpty;
    firstEmpty = toRemove;

    --listSize;

    return nodes[toRemove].value;
}

ListIterator IteratedList::search(TElem e) const {
    int current = head;
    while (current != NULL_INDEX) {
        if (nodes[current].value == e) {
            ListIterator it(*this);
            it.currentIndex = current;
            return it;
        }
        current = nodes[current].next;
    }

    ListIterator it(*this);
    it.currentIndex = NULL_INDEX;
    return it;
}
