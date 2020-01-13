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
    HuffNode* parent;
    HuffNode() {
        data = 0;
        weight = 0;
        depth = 0;
        flag = 0;
        leftchild = NULL;
        rightchild = NULL;
        parent = NULL;
    }
    HuffNode(char x, int freq, int dep, HuffNode* lc, HuffNode* rc){
        data = x;
        weight = freq;
        depth = dep;
        leftchild = lc;
        rightchild = rc;
        parent = NULL;
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
    void root_generate(const char* s); // transfer a string to a rootlist
    void root_sort(int left, int right); // sorting with range
    void HuffTree_create(); // each time create one at last and delete two at the beginning
    void isleaf(); // if lc = rc = NULL then a leaf
    void depth_calculate();
    void ratio_calculate(const char* s);
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
    /*
    for (int i = 0; i< listsize; i++){
        cout<<"data: "<<rootlist[i].data<<" "<<"weight: "<<rootlist[i].weight<<endl;
    }
    cout<<listsize<<endl;
    */
}

void HuffTree::root_sort(int left, int right) // left and right are certain
{
    for (int i = left; i <= right; i++){
        for (int j = i+1; j <= right; j++){
            if (rootlist[j].weight < rootlist[i].weight){
                swap(i,j);
            }
        }
    }
    /*
    for (int i = 0; i <= right; i++){
        cout<<"data: "<<rootlist[i].data<<" "<<"weight: "<<rootlist[i].weight<<endl;
    }
    cout<<listsize<<endl;
    */
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
        rootlist[listsize] = h3;
        listsize++;
        right++;
        left = left + 2;
    }
    for (int i = 0; i < listsize; i++){
        for (int j = 0; j < listsize; j++){
            HuffNode* temp = rootlist + i;
            if ( rootlist[j].leftchild == temp || rootlist[j].rightchild == temp){
                rootlist[i].parent = rootlist + j;
                break;
            }
        }
    } // find his father
    rootNode = rootlist+listsize-1;
    /*
    for (int i = 0; i < listsize; i++){
        cout<<"data: "<<rootlist[i].data<<" "<<"weight: "<<rootlist[i].weight<<" "<<"flag: "<<rootlist[i].flag<<" "<<"depth: "<<rootlist[i].depth<<" ";
        cout<<"self: "<<rootlist+i<<" "<<"parent: "<<rootlist[i].parent<<" "<<"leftchild: "<<rootlist[i].leftchild<<" "<<"rightchild: "<<rootlist[i].rightchild<<endl;
    }
    cout<<listsize<<endl;
    cout<<"rootNode: "<<rootNode<<endl;
    */
}

void HuffTree::isleaf()
{
    for (int i = 0; i < listsize; i++){
        HuffNode temp = rootlist[i];
        if( temp.leftchild == NULL & temp.leftchild == NULL) rootlist[i].flag = 1;
    }
    /*
    for (int i = 0; i < listsize; i++){
        cout<<"data: "<<rootlist[i].data<<" "<<"weight: "<<rootlist[i].weight<<" "<<"flag: "<<rootlist[i].flag<<" "<<"depth: "<<rootlist[i].depth<<" ";
        cout<<"self: "<<rootlist+i<<" "<<"parent: "<<rootlist[i].parent<<" "<<"leftchild: "<<rootlist[i].leftchild<<" "<<"rightchild: "<<rootlist[i].rightchild<<endl;
    }
    cout<<listsize<<endl;
    cout<<"rootNode: "<<rootNode<<endl;
    */
}


void HuffTree::depth_calculate()
{
    for (int i = 0; i < listsize; i++){
        HuffNode* temp = rootlist+i;
        if ( temp->flag == 1 ){
            while ( temp != rootNode ){
                rootlist[i].depth++;
                temp = temp->parent;
            }
        }
    }
    /*
    for (int i = 0; i < listsize; i++){
        cout<<"data: "<<rootlist[i].data<<" "<<"weight: "<<rootlist[i].weight<<" "<<"flag: "<<rootlist[i].flag<<" "<<"depth: "<<rootlist[i].depth<<" ";
        cout<<"self: "<<rootlist+i<<" "<<"parent: "<<rootlist[i].parent<<" "<<"leftchild: "<<rootlist[i].leftchild<<" "<<"rightchild: "<<rootlist[i].rightchild<<endl;
    }
    cout<<listsize<<endl;
    cout<<"rootNode: "<<rootNode<<endl;
    */
}

void HuffTree::ratio_calculate(const char* s)
{
    int length = 0;
    length = strlen(s);
    float sum = 0;
    for (int i = 0 ; i < listsize; i++){
        HuffNode temp = rootlist[i];
        if ( temp.flag == 1) sum = sum + temp.weight * temp.depth;
    }
    float asc = length * 8;
    float ratio = asc/sum;

    cout<<fixed<<setprecision(0)<<asc<<" "<<sum<<" ";
    cout<<fixed<<setprecision(1)<<ratio<<endl;
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
        huff.depth_calculate();
        huff.ratio_calculate(s);
    }
    //system("pause");
    return 0;
}
