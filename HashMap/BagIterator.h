#pragma once
#include "Bag.h"

class BagIterator {
    // DO NOT CHANGE THIS PART
    friend class Bag;

private:
    const Bag& bag;
    int currentIndex;
    int currentFreq;

    // Constructor
    BagIterator(const Bag& c);

public:
    // Sets the iterator to the first element
    void first();

    // Advances the iterator to the next element
    void next();

    // Checks if the iterator is valid
    bool valid() const;

    // Returns the current element
    TElem getCurrent() const;
};
