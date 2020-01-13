#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

char A[1000] = {0};
char B[1000] = {0};

class binaryTreeNode
{
public:
    char data;
    binaryTreeNode *leftChild;
    binaryTreeNode *rightChild;
    binaryTreeNode(){
        data = 0;
        leftChild = NULL;
        rightChild = NULL;
    }
    binaryTreeNode(char x){
        data = x;
        leftChild = NULL;
        rightChild = NULL;
    }
};

void Visit(binaryTreeNode *x)
{
    cout<<x->data;
}

void postOrder(binaryTreeNode *root)
{
    if (root != NULL){
        postOrder(root->leftChild);
        postOrder(root->rightChild);
        Visit(root);
    }
}

binaryTreeNode* buildTree(binaryTreeNode *root, int left, int right, int *index)
{
    int i = 0;
    char r = A[(*index)++];
    for ( i= left; i< right; i++ ){
        if ( B[i] == r ){
            root = new binaryTreeNode;
            root->data = r;
            break;
        }
    }
    if ( i > left && i < right )
        root->leftChild = buildTree(root->leftChild, left, i, index);
    if( i > left-1 && i < right-1 )
        root->rightChild = buildTree(root->rightChild, i+1, right, index);
    return root;
}

int main()
{
    int N;
    cin>>N;
    getchar();
    for (int k =0; k<N; k++){
        memset(A,0,sizeof(A));
	    memset(B,0,sizeof(B));
        cin>>A;
        getchar();
        cin>>B;
        int l;
        l = strlen(A);
        //cout<<l<<endl;
        binaryTreeNode *root = NULL;
        int index = 0;
        root = buildTree(root, 0, l, &index);
        postOrder(root);
        cout<<endl;
    }
    //system("pause");
    return 0;
}
