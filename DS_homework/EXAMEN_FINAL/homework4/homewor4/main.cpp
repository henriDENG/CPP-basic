#include<iostream>
#include<cstdlib>
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
        leftChild = rightChild = NULL;
    }
    binaryTreeNode(char &ch){
        data = ch;
        leftChild = rightChild = NULL;
    }
};

class binaryTree
{
private:
    binaryTreeNode *head;

public:
    binaryTree(){
        head = new binaryTreeNode;
    }
    binaryTree(binaryTreeNode *root){
        head = root;
    }
    ~binaryTree() {}
    void Visit(binaryTreeNode *x){ cout<<x->data; };
    void PostOrder(binaryTreeNode *root);
    binaryTreeNode* gethead(binaryTree t) { return t.head; }
    binaryTreeNode* buildTree(binaryTreeNode *root, int left, int right, int *index);
};

void binaryTree::PostOrder(binaryTreeNode *root)
{
    if ( root != NULL ){
        PostOrder(root->leftChild);
        PostOrder(root->rightChild);
        Visit(root);
    }
}

binaryTreeNode *binaryTree::buildTree(binaryTreeNode *root, int left, int right, int *index)
{
    int i = 0;
    int r = A[(*index)++];
    for ( i = left; i < right; i++ ){
        if ( B[i] == r )
            break;
    }
    root = new binaryTreeNode;
    root->data = r;
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
    for ( int i = 0; i < N; i++ ){
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        cin>>A;
        getchar();
        cin>>B;
        int l = strlen(A);
        binaryTree t;
        int index = 0;
        binaryTreeNode *root = t.gethead(t);

        root = t.buildTree(root, 0, l, &index);
        t.PostOrder(root);
        cout<<endl;
    }
    return 0;
}
