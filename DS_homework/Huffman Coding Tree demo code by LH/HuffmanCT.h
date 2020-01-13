#include <stdlib.h>
#include <iostream>
using namespace std;

#include "SLList.h"

template <class Elem>
class HuffNode{	// Node abstract base class
public:
	virtual int weight() = 0;
	virtual bool isLeaf() = 0;
	virtual HuffNode* left() const = 0;
	virtual void setLeft(HuffNode*) = 0;
	virtual HuffNode* right() const = 0;
	virtual void setRight(HuffNode*) = 0;
};

template <class Elem>
class FreqPair{ // An {elelment, frequency} pair
private:
	Elem it;	// An element of some sort
	int freq;	// Frequency for the element
public:
	FreqPair(const Elem& e, int f){ it = e; freq = f; }
	~FreqPair(){}
	int weight(){ return freq; }
	Elem& val(){ return it; }
};

template <class Elem> // Leaf node subclass
class LeafNode : public HuffNode<Elem> {
private:
	FreqPair<Elem>* it;
public:
	LeafNode(const Elem& val, int freq)
	{ it = new FreqPair<Elem>(val, freq); }
	int weight(){ return it->weight(); }
	FreqPair<Elem>* val(){ return it; }
	bool isLeaf(){ return true; }
	virtual HuffNode<Elem>* left() const { return NULL; }
	virtual void setLeft(HuffNode<Elem>*){}
	virtual HuffNode<Elem>* right() const { return NULL; }
	virtual void setRight(HuffNode<Elem>*){}
};

template <class Elem> // Internal node subclass
class IntlNode : public HuffNode<Elem> {
private:
	HuffNode<Elem>* lc;	// Left child
	HuffNode<Elem>* rc;	// Right child
	int wgt;		// Subtree weight
public:
	IntlNode(HuffNode<Elem>* l, HuffNode<Elem>* r)
	{ lc = l; rc = r; wgt = l->weight() + r->weight(); }
	int weight(){ return wgt; }
	bool isLeaf(){ return false; }
	HuffNode<Elem>* left() const { return lc; }
	void setLeft(HuffNode<Elem>* b){ lc = (HuffNode<Elem>*)b; }
	HuffNode<Elem>* right() const { return rc; }
	void setRight(HuffNode<Elem>* b){ rc = (HuffNode<Elem>*)b; }
};

// Huffman Coding Tree
template <class Elem>
class HuffTree {
private:
	HuffNode<Elem>* theRoot;
public:
	HuffTree(Elem& val, int freq)
	{ theRoot = new LeafNode<Elem>(val, freq); }
	HuffTree(HuffTree<Elem>* l, HuffTree<Elem>* r)
	{ theRoot = new IntlNode<Elem>(l->root(), r->root()); }
	~HuffTree(){}
	HuffNode<Elem>* root(){ return theRoot; }
	int weight(){ return theRoot->weight(); }
};

// Compare two Huffman coding trees by total weight
template <class Elem>
class HHCompare{
public:
	static bool lt(HuffTree<Elem>* x, HuffTree<Elem>* y)
	{ return x->weight() < y->weight(); }
	static bool eq(HuffTree<Elem>* x, HuffTree<Elem>* y)
	{ return x->weight() == y->weight(); }
	static bool gt(HuffTree<Elem>* x, HuffTree<Elem>* y)
	{ return x->weight() > y->weight(); }
};


// Build a Huffman tree from a sorted list 
template <class Elem>
HuffTree<Elem>* buildHuff(SLList<HuffTree<Elem>*, HHCompare<Elem>>* sf){
	HuffTree<Elem> *temp1, *temp2, *temp3;
	for(sf->setStart(); sf->leftLength()+sf->rightLength()>1; sf->setStart()){
		sf->remove(temp1); sf->remove(temp2); // Pull the first two trees off the list
		temp3 = new HuffTree<Elem>(temp1, temp2);
		sf->insert(temp3);
		delete temp1;
		delete temp2;
	}
	return temp3;
}

template <class Elem>
void traversePreOrder(HuffNode<Elem>* subroot){
        if (subroot==NULL) return; // an empty subtree branch
	if (subroot->isLeaf())
		cout << "Leaf node: (" << ((LeafNode<Elem>*)subroot)->val()->val() << " : " << ((LeafNode<Elem>*)subroot)->val()->weight() << ")\n";
	else{
		cout << "Internal node: (" << ((LeafNode<Elem>*)subroot)->weight() << ")\n";
                traversePreOrder(subroot->left());
                traversePreOrder(subroot->right());
        }
}


// Print a Huffman tree oriented sorted list
template <class Elem>
void printHuff(SLList<HuffTree<Elem>*, HHCompare<Elem>>* sf){
	HuffTree<Elem>* temp;
	for(sf->setStart(); sf->rightLength()!=0; sf->next()){
		sf->getValue(temp);
		if (temp->root()->isLeaf()){
			cout << ((LeafNode<Elem>*)temp->root())->val()->val() << "(" << temp->weight() << ") "; 
		}else{	cout << temp << "(" << temp->weight() << ") "; }
	}
	cout << endl;
}




