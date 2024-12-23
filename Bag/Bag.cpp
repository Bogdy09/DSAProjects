#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
    this->P_cap=10;
    this->P_size=0;
    this->P_elements=new TElem[P_cap];

    this->U_cap=10;
    this->U_size=0;
    this->U_elements=new TElem[U_cap];
}
//BC=WC=TC=theta(1)

void Bag::P_resize() {
        this->P_cap *= 2;
        auto *new_array = new TElem[this->P_cap];
        for (int i = 0; i < this->P_size; i++) {
            new_array[i] = this->P_elements[i];
        }
        delete[] this->P_elements;
        this->P_elements = new_array;
}

void Bag::U_resize(){
        this->U_cap*=2;
        auto *new_array=new TElem[this->U_cap];
        for(int i=0;i<this->U_size;i++){
            new_array[i]=this->U_elements[i];
        }
        delete[] this->U_elements;
        this->U_elements=new_array;
}

void Bag::add(TElem elem) {
    if(P_size==P_cap)
        P_resize();
    if(U_size==U_cap)
        U_resize();
    int ok=0, index, i;
    for(i=0;i<this->U_size;i++){
        int x = U_elements[i];
        if(U_elements[i]==elem) {
            index = i;
            ok = 1;
            break;
        }
    }
    if(ok==0){
        this->U_elements[this->U_size++]=elem;
        this->P_elements[this->P_size++]=this->U_size-1;
    }
    else{
        this->P_elements[this->P_size++]=index;
    }
}
//BC=WC=TC=O(U_size) BC=theta(1)

int Bag::search_position(TElem elem) const {
    for (int i = 0; i < this->U_size; i++)
        if (this->U_elements[i] == elem)
            return i;
    return -1;
}

/*
bool Bag::remove(TElem elem) {
    int index=-1, k=0;
    for(int i=0;i<this->U_size;i++){
        if(this->U_elements[i]==elem)
            index=i;
    }
    for(int i=0;i<this->P_size;i++){
        if(this->P_elements[i]==index){
            if(k==0){
                for(int j=i;j<this->P_size;j++)
                    this->P_elements[j]=this->P_elements[j+1];
                this->P_size--;
                i--;
            }
            k++;
        }
    }
    if(index==-1)
        return false;
    if(k==1){
        for(int i=index;i<this->U_size;i++)
            this->U_elements[i]=this->U_elements[i+1];
        this->U_size--;
    }
    return true;
}
*/
bool Bag::remove(TElem elem) {
    //TODO - Implementation
    if(!search(elem))
        return false;

    int index_of_element = search_position(elem);

    if(nrOccurrences(elem) == 1){
        for(int i = index_of_element; i < this->U_size - 1 ; i++)
            this->U_elements[i] = this->U_elements[i + 1];
        this->U_size--;

        int pos_of_index = -1;
        for(int i = 0; i < this->P_size; i++) {
            if (this->P_elements[i] == index_of_element)
                pos_of_index = i;
            if(this->P_elements[i] > index_of_element)
                this->P_elements[i]--;
        }
        this->P_elements[pos_of_index] = this->P_elements[this->P_size - 1];
        this->P_size--;

    } else if(nrOccurrences(elem) >= 1){
        int pos_of_index = -1;
        for(int i = 0; i < this->P_size; i++)
            if(this->P_elements[i] == index_of_element) {
                pos_of_index = i;
                break;
            }
        this->P_elements[pos_of_index] = this->P_elements[this->P_size - 1];
        this->P_size--;
    }
    return true;
}
// O(n) n - number of unique elements

int Bag::removeOccurences(int nr, TElem elem) {
    if(nr<0)
        throw exception();
    int k=0;
    if (!search(elem))
        return false;
    int l= nrOccurrences(elem);
    int index_of_element = search_position(elem);
    if (nrOccurrences(elem) <= nr) {
        for (int i = index_of_element; i < this->U_size - 1; i++)
            this->U_elements[i] = this->U_elements[i + 1];
        this->U_size--;

        for(int j=1;j<=l;j++) {
            int pos_of_index = -1;
            for (int i = 0; i < this->P_size; i++) {
                if (this->P_elements[i] == index_of_element)
                    pos_of_index = i;
                if (this->P_elements[i] > index_of_element)
                    this->P_elements[i]--;
            }
            this->P_elements[pos_of_index] = this->P_elements[this->P_size - 1];
            this->P_size--;
        }
    } else {
        int pos_of_index=0;
        for (int j = 1; j <= nr; j++) {
            for (int i = pos_of_index; i < this->P_size; i++)
                if (this->P_elements[i] == index_of_element) {
                    pos_of_index = i;
                    break;
                }
            k++;
            this->P_elements[pos_of_index] = this->P_elements[this->P_size - 1];
            this->P_size--;
        }
    }
    return k;
}
//BC=theta(1); WC=theta(P_size); AC=O(P_size)

bool Bag::search(TElem elem) const {
    for(int i=0;i<this->U_size;i++){
        if(this->U_elements[i]==elem)
            return true;
    }
    return false;
}

int Bag::nrOccurrences(TElem elem) const {
    int index=-1, k=0;
    for(int i=0;i<this->U_size;i++){
        if(this->U_elements[i]==elem)
            index=i;
    }
    for(int i=0;i<this->P_size;i++){
        if(this->P_elements[i]==index){
            k++;
        }
    }
    return k;
}


int Bag::size() const {
    return this->P_size;
}


bool Bag::isEmpty() const {
    if(this->size()==0 && this->U_size==0)
        return true;
    return false;
}

BagIterator Bag::iterator() const {
    return BagIterator(*this);
}

void Bag::displayElements() const {
    for (int i = 0; i < this->U_size; i++) {
        TElem elem = this->U_elements[i];
        int occurrences = this->nrOccurrences(elem);
        cout << "Element: " << elem << ", Occurrences: " << occurrences << endl;
    }
}

Bag::~Bag() {
    //TODO - Implementation
}


