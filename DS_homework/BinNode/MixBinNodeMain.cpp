#include "MixBinNode.h"

int main()
{
	// Create a BinNodePtr based binary tree
	BinNodePtr<int> A(2);
	BinNodePtr<int> B(3);
	BinNodePtr<int> C(5);
	A.setLeft(&B);
	A.setRight(&C);
	BinNodePtr<int> D(7);
	BinNodePtr<int> E(11);
	BinNodePtr<int> F(13);
	BinNodePtr<int> G(17);
	B.setLeft(&D);
	B.setRight(&E);
	C.setLeft(&F);
	C.setRight(&G);
	BinNodePtr<int> H(19);
	BinNodePtr<int> I(23);
	BinNodePtr<int> J(29);
	BinNodePtr<int> K(31);
	E.setLeft(&H);
	E.setRight(&I);
	F.setRight(&J);
	G.setLeft(&K);

	cout << "Create a BinNodePtr based binary tree \n";
	cout << "Traversal in pre-order ==> \n"; traversePreOrder(&A);
	//cout << "Traversal in post-order ==> \n"; traversePostOrder(&A);
	//cout << "Traversal in in-order ==> \n"; traverseInOrder(&A);

	/*
	A.~BinNodePtr();
	B.~BinNodePtr();
	C.~BinNodePtr();
	D.~BinNodePtr();
	E.~BinNodePtr();
	F.~BinNodePtr();
	G.~BinNodePtr();
	H.~BinNodePtr();
	I.~BinNodePtr();
	J.~BinNodePtr();
	K.~BinNodePtr();
	*/


	// Create a VarBinNode based binary tree
	VarBinNode<int> A2(2,NULL,NULL);
	VarBinNode<int> B2(3,NULL,NULL);
	VarBinNode<int> C2(5,NULL,NULL);
	A2.setLeft(&B2);
	A2.setRight(&C2);
	VarBinNode<int> D2(7);
	VarBinNode<int> E2(11,NULL,NULL);
	VarBinNode<int> F2(13,NULL,NULL);
	VarBinNode<int> G2(17,NULL,NULL);
	B2.setLeft(&D2);
	B2.setRight(&E2);
	C2.setLeft(&F2);
	C2.setRight(&G2);
	VarBinNode<int> H2(19);
	VarBinNode<int> I2(23);
	VarBinNode<int> J2(29);
	VarBinNode<int> K2(31);
	E2.setLeft(&H2);
	E2.setRight(&I2);
	F2.setRight(&J2);
	G2.setLeft(&K2);

	cout << "Create a VarBinNode based binary tree \n"; 
	cout << "Traversal in pre-order ==> \n"; traversePreOrder(&A2);
	//cout << "Traversal in post-order ==> \n"; traversePostOrder(&A2);
	//cout << "Traversal in in-order ==> \n"; traverseInOrder(&A2);

	return 0;
}

