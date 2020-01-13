#include<iostream>
#include<cstdlib>
#include <cstring>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int k=0;k<n;k++){
        char A1[500]={0};
        char A2[500]={0};
        int l1,l2;
        cin>>A1>>A2;
        l1=strlen(A1);
        l2=strlen(A2);
        for (int i=0;i<l1;i++){
            cout<<A1[i];
        }
        for (int j=0;j<l2;j++){
            cout<<A2[j];
        }
    cout<<endl;
    }

    return 0;
}
