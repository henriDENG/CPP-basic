#include "HuffmanCT.h"

int main()
{
	char letters[] = {'C', 'D', 'E', 'K', 'L', 'M', 'U', 'Z'};
	int freq[] = {32, 42, 120, 7, 42, 24, 37, 2};
	int num = 8;

	SLList<HuffTree<char>*, HHCompare<char>> sf;
	for(int i=0; i<num; i++) sf.insert(new HuffTree<char>(letters[i], freq[i]));
	sf.print();
	printHuff(&sf);
	HuffTree<char>* hf = buildHuff(&sf); printHuff(&sf);
	traversePreOrder(hf->root());


	return 0;
}

