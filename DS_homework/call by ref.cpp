#include<iostream>
using namespace std;
void increment(int&);

int main()
{
    int x;
    cin>>x;
    increment(x);//��C��ͬ�ĵط�����
    cout<<x;
    return 0;
}

void increment(int& x)//call by reference
{
    x++;
}
