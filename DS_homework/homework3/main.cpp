#include<iostream>
#include<cstring>
#include"class_Arraylist.h"

using namespace std;

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
