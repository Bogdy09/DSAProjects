#pragma once
#include "Set.h"

class SetIterator
{
    //DO NOT CHANGE THIS PART
    friend class Set;
private:
    //DO NOT CHANGE THIS PART
    Set& set;
    SetIterator(Set& s);
    Node* node;



public:
    TElem remove();
    void first();
    void next();
    TElem getCurrent();
    bool valid() const;
};


