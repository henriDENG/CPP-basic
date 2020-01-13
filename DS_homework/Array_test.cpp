#include<iostream>
#include<cstdlib>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstring>

int main()
{
   /* using namespace std;
    char A[100]={0};
    char ch;
    cin>>ch;
    //cout<<ch<<endl;
    int i=0,l=0;
    while (ch != 'a'){
        cout<<ch<<endl;
        A[i++]=ch;
        cout<<"hh"<<A[i-1]<<endl;
        cout<<"hhh"<<i<<endl;
        cin>>ch;
    }

    l=i;
    cout<<"value of l: "<<i<<endl;
    for (int j=0;j<l;j++){ cout<<A[j];}
    cout<<endl;*/

    /*
    using namespace std;
    char A[100];
    char ch;
    ch=getchar();
    int i=0;
    while(ch != '\n'){
        A[i++]=ch;
        cout<<"hh"<<A[i-1]<<endl;
        cout<<"hhh"<<i<<endl;
        ch=getchar();
    }
    for (int j=0;j<i;j++){
        cout<<A[j];
    }
    */
    using namespace std;
    char num[100]={0};
    int length;
    while(cin>>num){
        length=strlen(num);
        for(int i=length-1;i>=0;i--){
        cout<<num<<endl;
        }
        cout<<length;
    }

    return 0;// cinh会跳过制表符、空格符、回车等，不读入
}
