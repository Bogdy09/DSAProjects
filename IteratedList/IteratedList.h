#pragma once
#include "ListIterator.h"

class ListIterator;
#define NULL_TELEM -11111
typedef int TElem;

class IteratedList {
private:
    struct Node {
        TElem value;
        int next;
    };

    Node* nodes;
    int capacity;
    int head;
    int firstEmpty;
    int listSize;

    void resize();

    friend class ListIterator;

public:
    IteratedList();
    ~IteratedList();

    int size() const;
    bool isEmpty() const;
    ListIterator first() const;
    TElem getElement(ListIterator pos) const;
    TElem setElement(ListIterator pos, TElem e);
    void addToEnd(TElem e);
    void addToBeginning(TElem e);
    void addToPosition(ListIterator& pos, TElem e);
    TElem remove(ListIterator& pos);
    ListIterator search(TElem e) const;
};
