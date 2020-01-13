#include<iostream>//流输入输出

using namespace std;//在std框架下用cout，等于std::cout

int main()
{   int a,b,c;
   /* cin>>a;
    cin>>b;
    cin>>c;//把输入的东西赋给变量
    cout<<"value of a: "<<a<<endl<<"value of b: "<<b<<endl<<"value of c: "<<c<<endl;//换行可以用<<endl或<<"\n"，<<endl刷新了流
    */
    char name[100];
    int age;
    cin>>name>>age;

    cout<<"Your name is: "<<name<<endl<<"Your age is: "<<age<<endl;
    return 0;
}


//把文件和变量关联后，对变量进行操作，fin.close/ fout.close,.close才意味着写入内存块，文件被改变，
//否则之前的操作不会对文件有映像

