#include <iostream>
using namespace std;

#include "LList.h"

/****************************
SLLlist: Sorted Linked List
  Class SLList inherits class LList as a protected base class. In this way, the LList functionality is not directly available to the user of class SLList. In fact, some stuffs in LList such as append() are meaningless to SLList and these stuffs had better be kept hidden from users' perspective.
  However, many of the LList functions are useful to the SLList user. Thus, most of the LList functions are passed along directly to the SLList user without change. On the other hand, the insert() function is replaced, whereas the append() function is kept hidden.
****************************/
template <class Elem, class Comp>
class SLList: protected LList<Elem>{
public:
	SLList(int size=DEFAULT_LIST_SIZE) : LList<Elem>(size){}
	~SLList(){}
	using LList<Elem>::clear;	// Expose the LList clear method
	bool insert(const Elem& item){
		Elem curr;
		for (setStart(); getValue(curr); next())
			if (!Comp::lt(curr, item)) break;
		return LList<Elem>::insert(item);
	}
	// Expose the following LList methods from protected (hidden) mode
	using LList<Elem>::remove;
	using LList<Elem>::setStart;
	using LList<Elem>::setEnd;
	using LList<Elem>::prev;
	using LList<Elem>::next;
	using LList<Elem>::leftLength;
	using LList<Elem>::rightLength;
	using LList<Elem>::setPos;
	using LList<Elem>::getValue;
	using LList<Elem>::print;
};



