#pragma once
//DO NOT INCLUDE SETITERATOR

//DO NOT CHANGE THIS PART
#define NULL_TELEM -111111
typedef int TElem;
class SetIterator;

struct Node{
    Node* next;
    TElem elem;
};

class Set {
    //DO NOT CHANGE THIS PART
    friend class SetIterator;

private:
    //TODO - Representation
    int _size=0;
    Node* head;
    Node* get_last();

public:
    //implicit constructor
    Set();

    //adds an element to the set
    //returns true if the element was added, false otherwise (if the element was already in the set and it was not added)
    bool add(TElem e);

    //removes an element from the set
    //returns true if e was removed, false otherwise
    bool remove(TElem e);

    //checks whether an element belongs to the set or not
    bool search(TElem elem) const;

    //returns the number of elements;
    int size() const;

    //check whether the set is empty or not;
    bool isEmpty() const;

    //return an iterator for the set
    SetIterator iterator();

    // destructor
    ~Set();

};





