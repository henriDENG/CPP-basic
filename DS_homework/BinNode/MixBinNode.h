#include <stdlib.h>
#include <iostream>
#include "BinNode.h"
using namespace std;

template <class Elem>
class BinNodePtr : public BinNode<Elem> {
private:
	Elem it; 	// The node's value
	BinNodePtr* lc;	// Pointer to left child
	BinNodePtr* rc;	// Pointer to right child
public:
	BinNodePtr() { lc = rc = NULL; }
	BinNodePtr(Elem e, BinNodePtr* l=NULL, BinNodePtr* r=NULL)
	{ it = e; lc = l; rc = r; }
	~BinNodePtr(){}
	Elem& val(){ return it; }
	void setVal(const Elem& e){ it = e; }
	inline BinNode<Elem>* left() const { return lc; }
	//inline BinNodePtr<Elem>* left() const { return lc; }
	void setLeft(BinNode<Elem>* b){ lc = (BinNodePtr*)b; }
	inline BinNode<Elem>* right() const { return rc; }
	//inline BinNodePtr<Elem>* right() const { return rc; }
	void setRight(BinNode<Elem>* b){ rc = (BinNodePtr*)b; }
	bool isLeaf() { return (NULL==lc) && (NULL==rc); }
};

#define leaf 0
#define internal 1
template <class Elem> 
class VarBinNode : public BinNode<Elem> {
private:
        int mytype;
        union{
                struct{
                        Elem intl_val;  // The node's value
                        VarBinNode* lc; // Pointer to left child
                        VarBinNode* rc; // Pointer to right child
                } intl;                 // Internal node
                Elem leaf_val;          // Leaves just store a value
        };
public:
        VarBinNode(const Elem& val)
        { mytype = leaf; leaf_val = val; }
        VarBinNode(const Elem& val, VarBinNode* l, VarBinNode* r)
        { mytype = internal; intl.intl_val = val; intl.lc = l; intl.rc = r; }
        ~VarBinNode(){}
        bool isLeaf(){ return mytype==leaf; }
        Elem& val(){
                if (mytype==leaf) return leaf_val;
                else return intl.intl_val;
        }
        void setVal(const Elem& e){
                if (mytype==leaf) leaf_val = e;
                else intl.intl_val = e;
        }
        BinNode<Elem>* left() const {return intl.lc; }
        void setLeft(BinNode<Elem>* b){ intl.lc = (VarBinNode*)b; }
        BinNode<Elem>* right() const {return intl.rc; }
        void setRight(BinNode<Elem>* b){ intl.rc = (VarBinNode*)b; }
};


template <class Elem>
void traversePreOrder(BinNode<Elem>* subroot){
//void traversePreOrder(BinNodePtr<Elem>* subroot){
	if (subroot==NULL) return; // an empty subtree branch
	if (subroot->isLeaf())
		cout << "Leaf node: " << subroot->val() << "\n";
	else{
		cout << "Internal node: " << subroot->val() << "\n";
		traversePreOrder(subroot->left());
		traversePreOrder(subroot->right());
	}
}

template <class Elem>
void traversePostOrder(BinNode<Elem>* subroot){
	if (subroot==NULL) return; // an empty subtree branch
	if (subroot->isLeaf())
		cout << "Leaf node: " << subroot->val() << "\n";
	else{
		traversePostOrder(subroot->left());
		traversePostOrder(subroot->right());
		cout << "Internal node: " << subroot->val() << "\n";
	}
}

template <class Elem>
void traverseInOrder(BinNode<Elem>* subroot){
	if (subroot==NULL) return; // an empty subtree branch
	if (subroot->isLeaf())
		cout << "Leaf node: " << subroot->val() << "\n";
	else{
		traverseInOrder(subroot->left());
		cout << "Internal node: " << subroot->val() << "\n";
		traverseInOrder(subroot->right());
	}
}



