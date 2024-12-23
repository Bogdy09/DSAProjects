#include "BagIterator.h"

// Constructor
BagIterator::BagIterator(const Bag& c) : bag(c), currentIndex(0), currentFreq(0) {
    first();
}

// Sets the iterator to the first element
void BagIterator::first() {
    currentIndex = 0;
    currentFreq = 0;
    while (currentIndex < bag.capacity && (bag.table[currentIndex] == NULL_TELEM || bag.table[currentIndex] == DELETED_TELEM)) {
        currentIndex++;
    }
}

// Advances the iterator to the next element
void BagIterator::next() {
    if (!valid()) {
        throw std::out_of_range("Iterator out of range");
    }

    currentFreq++;
    if (currentFreq >= bag.frequency[currentIndex]) {
        currentIndex++;
        currentFreq = 0;
        while (currentIndex < bag.capacity && (bag.table[currentIndex] == NULL_TELEM || bag.table[currentIndex] == DELETED_TELEM)) {
            currentIndex++;
        }
    }
}

// Checks if the iterator is valid
bool BagIterator::valid() const {
    return currentIndex < bag.capacity && bag.table[currentIndex] != NULL_TELEM && bag.table[currentIndex] != DELETED_TELEM;
}

// Returns the current element
TElem BagIterator::getCurrent() const {
    if (!valid()) {
        throw std::out_of_range("Iterator out of range");
    }
    return bag.table[currentIndex];
}
