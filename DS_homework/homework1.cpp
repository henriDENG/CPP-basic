#include<iostream>
#include<iomanip>
using namespace std;

void transition();

void transition()
{
    char ch;
    double a;
    cin>>ch>>a;
    if (ch == 'C')
        cout<<fixed<<setprecision(2)<<a*1.8+32<<endl;//fixed�̶�С����λ�ã�setprecision����С�����λ��
    else
        cout<<fixed<<setprecision(2)<<(a-32)/1.8<<endl;
}

int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        transition();
    }

    return 0;
}
