#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

class BSTNode
{
public:
    int data;
    BSTNode *left, *right;
    BSTNode(){
        data = 0;
        left = NULL;
        right = NULL;
    };
    BSTNode(int val){
        data = val;
        left = NULL;
        right = NULL;
    };
};

class BSTTree
{
private:
    void Clear(BSTNode* t){
        if (t != NULL){
            Clear(t->left);
            Clear(t->right);
            delete t;
            t = NULL;
        }
    }

public:
    BSTNode* root;
    BSTTree() { root = NULL; };
    ~BSTTree() { Clear(root); };

    void visit(BSTNode *t){ cout<<t->data<<" "; };
    void inOrder(BSTNode *root);

    void insert(BSTNode *t, int val);  // Insert the value to the BST
    BSTNode* find(BSTNode *t, int val);  // Find the node
    BSTNode* lowestCommonAncestor(BSTNode* root, BSTNode* p, BSTNode* q);  // Return the lowest common ancestor node in the BST

};

void BSTTree::inOrder(BSTNode *root)
{
    if (root != NULL){
        inOrder(root->left);
        visit(root);
        inOrder(root->right);
    }
}

void BSTTree::insert(BSTNode* t, int val)
{
    if (val < t->data){

		if (t->left == NULL){
			BSTNode *temp = new BSTNode(val);
			t->left = temp;
		}
		else
			insert(t->left, val);
	}

	else if (val > t->data){

		if (t->right == NULL){
			BSTNode *temp = new BSTNode(val);
			t->right = temp;
		}
		else
			insert(t->right, val);
	}
}

BSTNode* BSTTree::find(BSTNode* t, int val)
{
    if ( t == NULL)
        return NULL;

    if( val < t->data){
        find(t->left, val);
    }

    else if ( val > t->data){
        find(t->right, val);
    }
    else
        return t;
}

BSTNode* BSTTree::lowestCommonAncestor(BSTNode* root, BSTNode* p, BSTNode* q)
{
	if (root == NULL || p == NULL || q == NULL)
		return NULL;

	if ( (p->data < root->data) && (q->data < root->data) )
	{
		lowestCommonAncestor(root->left, p, q);
	}
	else if ( (p->data > root->data) && (q->data > root->data) )
	{
		lowestCommonAncestor(root->right, p, q);
	}
	else
		return root;
}

int main()
{
    int N;
    cin>>N;

    for (int i = 0; i< N; i++){
        BSTTree T;
        int M;
        cin>>M;
        int temp;
        for (int i = 0; i < M; i++)
        {
            if (i == 0){
                cin>>temp;
                T.root = new BSTNode(temp);
                //cout<<"value of rootNode: "<<T.root->data<<endl;
            }
            else{
                cin >> temp;
                T.insert(T.root, temp);
            }
        }

        // T.inOrder(T.root);
        // cout<<endl;
        // print the sequence

        int a,b;
        cin>>a>>b;
        BSTNode* p;
        BSTNode* q;
        p = T.find(T.root, a);
        q = T.find(T.root, b);
        //cout<<"value of a: "<<p->data<<" "<<"value of b: "<<q->data<<endl;

        BSTNode* r;
        r = T.lowestCommonAncestor(T.root, p, q);
        cout<<r->data<<endl;

    }
    // Obtain the lowest common ancestor
    return 0;

}
