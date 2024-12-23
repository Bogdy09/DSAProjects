#pragma once
#include <stdexcept>

#define INITIAL_CAPACITY 8
#define LOAD_FACTOR_THRESHOLD 0.7
#define NULL_TELEM -111111
#define DELETED_TELEM -222222

typedef int TElem;

class BagIterator;

class Bag {
private:
    TElem* table; // The hash table
    int* frequency; // Frequency of elements for each slot in the table
    int capacity; // Capacity of the table
    int size; // Total number of elements in the bag
    int numElements; // Number of occupied slots (including DELETED_TELEM)

    // Primary hash function
    int hash1(TElem e) const;

    // Secondary hash function
    int hash2(TElem e) const;

    // Resize and rehash the table when the load factor exceeds the threshold
    void resizeAndRehash();

public:
    // Constructor
    Bag();

    // Destructor
    ~Bag();

    // Adds an element to the bag
    void add(TElem e);

    // Removes one occurrence of an element from the bag
    bool remove(TElem e);

    // Checks if an element appears in the bag
    bool search(TElem e) const;

    // Returns the number of occurrences for an element in the bag
    int nrOccurrences(TElem e) const;

    // Returns the number of elements in the bag
    int size() const;

    // Checks if the bag is empty
    bool isEmpty() const;

    // Returns an iterator for the bag
    BagIterator iterator() const;
};
