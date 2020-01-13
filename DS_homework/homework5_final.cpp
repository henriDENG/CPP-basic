#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

char A[1000] = {0};
char B[1000] = {0};

template <class T>
class binaryTreeNode
{
public:
    T data;
    binaryTreeNode<T> *leftChild;
    binaryTreeNode<T> *rightChild;
    binaryTreeNode(){
        data = 0;
        leftChild = NULL;
        rightChild = NULL;
    }
    binaryTreeNode(T &x){
        data = x;
        leftChild = NULL;
        rightChild = NULL;
    }
};

template <class T>
class binaryTree
{
private:
    binaryTreeNode<T>* headNode;
    void init(){
        headNode = new binaryTreeNode<T>;
        headNode->data = 0;
        headNode->leftChild = NULL;
        headNode->rightChild = NULL;
        //left = right =0;
    };
    void Clear(binaryTreeNode<T> *x){
        if ( x != NULL ){
            Clear(x->leftChild);
            Clear(x->rightChild);
            delete x;
            x = NULL;
        }
    }

public:
    binaryTree() { init(); };
    binaryTree(const binaryTree<T> &t) { headNode = t.headNode; };
    ~binaryTree() { Clear(headNode); };
    void Visit(binaryTreeNode<T> *x){ cout<<x->data; };
    void postOrder(binaryTreeNode<T> *root);
    binaryTreeNode<T>* buildTree(binaryTreeNode<T> *root, int left, int right, int *index);
    binaryTreeNode<T>* getHead(binaryTree<T> t){
        binaryTreeNode<T> *p = t.headNode;
        return p;
    }
};

template <typename T>
void binaryTree<T>::postOrder(binaryTreeNode<T> *root)
{
    if (root != NULL){
        postOrder(root->leftChild);
        postOrder(root->rightChild);
        Visit(root);
    }
}

template <typename T>
binaryTreeNode<T> *binaryTree<T>::buildTree(binaryTreeNode<T> *root, int left, int right, int *index)
{
    int i = 0;
    int r = A[(*index)++];
    for ( i= left; i< right; i++ ){
        if ( B[i] == r )
            break;
    }
    root = new binaryTreeNode<T>;
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
    getchar();
    for (int k=0;k<N;k++){
        memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
        cin>>A;
        getchar();
        cin>>B;
        int l;
        l = strlen(A);
        binaryTree<char> t;
        binaryTreeNode<char> *root = t.getHead(t);
        int index = 0;
        root = t.buildTree(root, 0, l, &index);
        t.postOrder(root);
        cout<<endl;
    }
    return 0;
}
