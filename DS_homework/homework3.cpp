#include<iostream>
#include<cstring>

using namespace std;

class Arraylist
{
private:
    int maxsize;
    int listsize;
    int fence;
    char* listArray;
public:
    Arraylist();
    Arraylist(const Arraylist &);
    ~Arraylist();
    void Add(const char ch);
    void Copy(const char* Array);
    bool Remove(int pos, char *it);
    void Combination(const Arraylist &b);//如果不是传引用，会自动调用拷贝构造函数，将指针复制，指向同一片内存区域
    void Clear();
    char*Getlist();
    char Getvalue(int pos);
    void show();

};

Arraylist::Arraylist()
{
    maxsize=200;
    listsize=0;
    fence=0;//指向末尾元素,除了remove时
    listArray = new char[maxsize];

}

Arraylist::Arraylist(const Arraylist &obj)//自定义拷贝构造函数，在传值时候自动调用
{
    maxsize = obj.maxsize;
    listsize=obj.listsize;
    fence=obj.fence;
    listArray = new char[maxsize];
    for (int i = 0; i < maxsize; i++){
        listArray[i] = obj.listArray[i];
    //cout<<"CONSTRUCTOR"<<endl;
    }
}

Arraylist::~Arraylist()
{
    if (listArray)
        delete [] listArray;
    //cout<<"bye!"<<endl;
}


void Arraylist::Add(const char ch)
{
    listArray[listsize]=ch;
    listsize++;
    fence=listsize-1;

}

void Arraylist::Copy(const char *Array)
{

    int length=strlen(Array);
    listsize=length;
    for (int i=0;i<length;i++){
        listArray[i]=Array[i];
    }
    fence=listsize-1;
   // cout << "COPY\n";
}

bool Arraylist::Remove(int pos, char* it)
{
    fence=pos;
    if (fence>=listsize) return false;
    else{
        it = listArray+fence;
        for (int i=fence;i<listsize;i++){
            listArray[i]=listArray[i+1];
        }
        listsize--;
        return true;
    }
}

void Arraylist::Combination(const Arraylist &b)
{
    char temp;
    int length_a,length_b;
    length_a = listsize;
    length_b = b.listsize;
    //cout<<"length of a: "<<length_a<<endl;
    //cout<<"length of b: "<<length_b<<endl;

    for (int j=0;j<length_b;j++){
        temp=b.listArray[j];
       // cout<<"elements of b: "<<temp<<endl;
        Add(temp);
    }

    listsize = length_a + length_b;
    //cout<<"length of combination: "<<listsize<<endl;
    fence=listsize-1;
    //cout << "COMBINATION\n";
}

void Arraylist::Clear()
{
    delete [] listArray;
    int listsize=0;
    int fence=0;
    listArray = new char[maxsize];

}


char *Arraylist::Getlist()
{
    return listArray;
}

char Arraylist::Getvalue(int pos)
{
    char temp;
    temp = listArray[pos];
    return temp;
}

void Arraylist::show()
{
    for(int i=0;i<listsize;i++){
        cout<<listArray[i];
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    for (int k=0;k<n;k++){
        char A1[200]={0};
        char A2[200]={0};
        cin>>A1>>A2;
        Arraylist a,b;
        a.Copy(A1);
        b.Copy(A2);
        a.Combination(b);
        a.show();
    }

    return 0;
}

