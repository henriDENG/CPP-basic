#include<iostream>
using namespace std;
void increment(int&);

int main()
{
    int x;
    cin>>x;
    increment(x);//与C不同的地方！！
    cout<<x;
    return 0;
}

void increment(int& x)//call by reference
{
    x++;
}
