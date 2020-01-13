#include<iostream>
#include<cstring>
#include"class_Arraylist.h"

using namespace std;

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


