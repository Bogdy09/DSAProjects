#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
    this->P_position=0;
}

void BagIterator::first() {
    this->P_position=0;
}


void BagIterator::next() {
    if(valid()){
        P_position+=1;
    }
    else
        throw std::exception();

}


bool BagIterator::valid() const {
    if(this->P_position<bag.P_size)
        return true;
    return false;
}



TElem BagIterator::getCurrent() const
{
    //TODO - Implementation
    if(valid())
        return bag.U_elements[bag.P_elements[P_position]];
    else
        throw std::exception();
}