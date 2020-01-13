#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>

using namespace std;

int MAXSIZE = 100;

class HuffNode
{
public:
    char data;
    int weight;
    int depth;
    int flag;
    HuffNode* leftchild;
    HuffNode* rightchild;
    HuffNode() {
        data = 0;
        weight = 0;
        depth = 0;
        flag = 0;
        leftchild = NULL;
        rightchild = NULL;
    }
    HuffNode(char x, int freq, int dep, HuffNode* lc, HuffNode* rc){
        data = x;
        weight = freq;
        depth = dep;
        leftchild = lc;
        rightchild = rc;
        flag = 0;
    }
};

class HuffTree
{
private:
    HuffNode* rootNode; // rootNode of the whole tree
    HuffNode* rootlist;  // all the HuffNodes
    int listsize;  // size of rootlist
    void swap(int a, int b){
        HuffNode temp = rootlist[a];
        rootlist[a] = rootlist[b];
        rootlist[b] = temp;
    }
public:
    HuffTree(){
        rootNode = NULL;
        rootlist = new HuffNode[MAXSIZE];
        listsize = 0;
    }
    HuffTree(const HuffTree &h){
        rootNode = h.rootNode;
        rootlist = new HuffNode[MAXSIZE];
        for (int i = 0; i < h.listsize; i++){
            rootlist[i] = h.rootlist[i];
        }
        listsize = h.listsize;
    }
    ~HuffTree(){
        rootNode = NULL;
        delete []rootlist;
        rootlist = NULL;
        listsize = 0;
    }
    void root_generate(const char* s); // transfer tne string to a rootlist
    void root_sort(int left, int right); // sorting with range
    void HuffTree_create(); // each time create one at last and delete two at the beginning
    void isleaf(); // if lc = rc = NULL then a leaf
    void Visit(HuffNode* x, int n); // visit a HuffNode and recursion
    void dep_preOrder(HuffNode* root, int n); // to visualize the HuffTree and get depth
    void ratio_calculate(const char *s);
    void show(); // print the detail of the HuffTree
    int get_listsize() { return listsize; }
    HuffNode* get_rootNode() { return rootNode; }
};

void HuffTree::root_generate(const char* s)
{
    int length = 0;
    length = strlen(s);
    char ref[MAXSIZE];
    strcpy(ref, "_ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    HuffNode* total = new HuffNode[MAXSIZE];
    for (int i = 0; i < length; i++){
        for (int j = 0; j <= 26; j++){
            if ( s[i] == ref[j] ){
                total[j].data = ref[j];
                total[j].weight++;
                break;
            }
        }
    }
    for (int k = 0; k <= 26; k++){
        if ( total[k].weight != 0 ){
            rootlist[listsize++] = total[k];
        }
    }
}

void HuffTree::root_sort(int left, int right) // left and right are certain
{
    for (int i = left; i <= right; i++){
        for (int j = i+1; j <= right; j++){
            if (rootlist[j].weight <= rootlist[i].weight){
                swap(i,j);
            }
        }
    }
}

void HuffTree::HuffTree_create()
{
    int count = listsize-1;
    int left = 0;
    int right = listsize - 1;
    for (int i = 1; i <= count; i++){
        root_sort(left,right);
        HuffNode h1 = rootlist[left];
        HuffNode h2 = rootlist[left+1];
        HuffNode h3 = HuffNode(0, h1.weight + h2.weight, 0, rootlist + left , rootlist + left + 1);
        rootlist[listsize++] = h3;
        right++;
        left = left + 2;
    }
    rootNode = rootlist+listsize-1;
}

void HuffTree::isleaf()
{
    for (int i = 0; i < listsize; i++){
        HuffNode temp = rootlist[i];
        if( temp.leftchild == NULL & temp.leftchild == NULL) rootlist[i].flag = 1;
    }
}

void HuffTree::Visit(HuffNode* x, int n)
{
    //cout<<x->weight<<" ";
    if ( x->flag == 1 ){
        for (int i = 0; i < listsize; i++){
            if (rootlist[i].data == x->data){
                rootlist[i].depth = n;
                break;
            }
        }
    }
}

void HuffTree::dep_preOrder(HuffNode* root, int n)
{
    if ( root != NULL ){
        Visit(root, n);
        dep_preOrder(root->leftchild, n+1);
        dep_preOrder(root->rightchild, n+1);
    }
}

void HuffTree::ratio_calculate(const char* s)
{
    int length = strlen(s);
    float asc = length * 8;
    float sum = 0;
    for (int i = 0; i < listsize; i++){
        if ( rootlist[i].flag == 1) sum = sum + rootlist[i].weight * rootlist[i].depth;
    }
    float ratio;
    ratio = asc/sum;
    cout<<fixed<<setprecision(0)<<asc<<" "<<sum<<" ";
    cout<<fixed<<setprecision(1)<<ratio<<endl;
}

void HuffTree::show()
{
    for (int i = 0; i < listsize; i++){
        cout<<"data: "<<rootlist[i].data<<" "<<"weight: "<<rootlist[i].weight<<" "<<"flag: "<<rootlist[i].flag<<" "<<"depth: "<<rootlist[i].depth<<" ";
        cout<<"self: "<<rootlist+i<<" "<<"leftchild: "<<rootlist[i].leftchild<<" "<<"rightchild: "<<rootlist[i].rightchild<<endl;
    }
    cout<<listsize<<endl;
}

int main()
{
    char s[100];
    while (cin>>s){
        if ( strcmp(s, "END") == 0 ) break;
        HuffTree huff;
        huff.root_generate(s);
        huff.HuffTree_create();
        huff.isleaf();
        HuffNode* root;
        root = huff.get_rootNode();
        int n = 0;
        huff.dep_preOrder(root, n);
        huff.ratio_calculate(s);
        //huff.show();
    }
    //system("pause");
    return 0;
}
