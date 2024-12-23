#include "Bag.h"

// Primary hash function
int Bag::hash1(TElem e) const {
    return e % capacity;
}

// Secondary hash function
int Bag::hash2(TElem e) const {
    return 1 + (e % (capacity - 1));
}

// Resize and rehash the table when the load factor exceeds the threshold
void Bag::resizeAndRehash() {
    int oldCapacity = capacity;
    capacity *= 2;
    TElem* oldTable = table;
    int* oldFrequency = frequency;
    table = new TElem[capacity];
    frequency = new int[capacity];
    for (int i = 0; i < capacity; ++i) {
        table[i] = NULL_TELEM;
        frequency[i] = 0;
    }
    numElements = 0;

    for (int i = 0; i < oldCapacity; ++i) {
        if (oldTable[i] != NULL_TELEM && oldTable[i] != DELETED_TELEM) {
            for (int j = 0; j < oldFrequency[i]; ++j) {
                add(oldTable[i]);
            }
        }
    }

    delete[] oldTable;
    delete[] oldFrequency;
}

// Constructor
Bag::Bag() : capacity(INITIAL_CAPACITY), size(0), numElements(0) {
    table = new TElem[capacity];
    frequency = new int[capacity];
    for (int i = 0; i < capacity; ++i) {
        table[i] = NULL_TELEM;
        frequency[i] = 0;
    }
}

// Destructor
Bag::~Bag() {
    delete[] table;
    delete[] frequency;
}

// Adds an element to the bag
void Bag::add(TElem e) {
    if ((numElements + 1) / static_cast<float>(capacity) > LOAD_FACTOR_THRESHOLD) {
        resizeAndRehash();
    }

    int hash1Value = hash1(e);
    int hash2Value = hash2(e);
    int i = 0;

    while (table[(hash1Value + i * hash2Value) % capacity] != NULL_TELEM &&
           table[(hash1Value + i * hash2Value) % capacity] != DELETED_TELEM &&
           table[(hash1Value + i * hash2Value) % capacity] != e) {
        i++;
    }

    int position = (hash1Value + i * hash2Value) % capacity;

    if (table[position] == e) {
        frequency[position]++;
    } else {
        table[position] = e;
        frequency[position] = 1;
        numElements++;
    }

    size++;
}

// Removes one occurrence of an element from the bag
bool Bag::remove(TElem e) {
    int hash1Value = hash1(e);
    int hash2Value = hash2(e);
    int i = 0;

    while (table[(hash1Value + i * hash2Value) % capacity] != NULL_TELEM) {
        int position = (hash1Value + i * hash2Value) % capacity;
        if (table[position] == e) {
            frequency[position]--;
            size--;
            if (frequency[position] == 0) {
                table[position] = DELETED_TELEM;
                numElements--;
            }
            return true;
        }
        i++;
    }

    return false;
}

// Checks if an element appears in the bag
bool Bag::search(TElem e) const {
    int hash1Value = hash1(e);
    int hash2Value = hash2(e);
    int i = 0;

    while (table[(hash1Value + i * hash2Value) % capacity] != NULL_TELEM) {
        int position = (hash1Value + i * hash2Value) % capacity;
        if (table[position] == e) {
            return true;
        }
        i++;
    }

    return false;
}

// Returns the number of occurrences for an element in the bag
int Bag::nrOccurrences(TElem e) const {
    int hash1Value = hash1(e);
    int hash2Value = hash2(e);
    int i = 0;

    while (table[(hash1Value + i * hash2Value) % capacity] != NULL_TELEM) {
        int position = (hash1Value + i * hash2Value) % capacity;
        if (table[position] == e) {
            return frequency[position];
        }
        i++;
    }

    return 0;
}

// Returns the number of elements in the bag
int Bag::size() const {
    return size;
}

// Checks if the bag is empty
bool Bag::isEmpty() const {
    return size == 0;
}

// Returns an iterator for the bag
BagIterator Bag::iterator() const {
    return BagIterator(*this);
}
