#include "Bag.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
#include <iostream>
#include <assert.h>

using namespace std;

void TestRemoveOccurences(int nr, TElem elem){
    Bag b;
    assert(b.size()==0);
    b.add(5);
    b.add(3);
    b.add(5);
    b.add(5);
    b.removeOccurences(2, 5);
    assert(b.size()==2);
    b.add(3);
    assert(b.size()==3);
    b.removeOccurences(2, 3);
    assert(b.size()==1);
    b.removeOccurences(10, 5);
    assert(b.size()==0);
}
int main() {
    TestRemoveOccurences(3, 5);
    cout<<"yas";
	testAll();
	cout << "Short tests over" << endl;
	testAllExtended();
    cout << "All test over" << endl;
}