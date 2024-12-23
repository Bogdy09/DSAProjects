#include "Set.h"
#include "SetIterator.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include <stack>
#include <iostream>
#include <assert.h>
using namespace std;

void test(){
    Set s;
    assert(s.isEmpty() == true);
    assert(s.size() == 0);
    assert(s.add(5)==true);
    assert(s.add(1)==true);
    assert(s.add(10)==true);
    assert(s.add(7)==true);
    assert(s.add(1)==false);
    assert(s.add(10)==false);
    assert(s.add(-3)==true);
    assert(s.add(12)==true);
    assert(s.add(45)==true);
    SetIterator it = s.iterator();
    it.first();
    cout<<it.remove()<<'\n'; //removes 5
    it.next();
    assert(it.getCurrent()==10);
    cout<<it.remove()<<'\n';
    assert(it.getCurrent()==7);
    it.next();
    it.next();
    cout<<it.remove()<<'\n';

}


int main() {

	//testAll();
	//testAllExtended();
    test();


	cout << "That's all!" << endl;
	system("pause");

}




