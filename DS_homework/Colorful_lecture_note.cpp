#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;
int height = 0;
string my_stack[100];

void pop()
{
    height--;
}

void push(string ss)
{
    height++;
    my_stack[height] = ss;
}

void count(string ss, int *Note)
{
    int length = ss.length();
    int flag = 0;
    int begin = 0;
    int ll = 0;
    int i = 0;
    while( i < length){
        flag = 0;
        ll = 0;
        if ( ss.substr(i,2) == "<r"){
            push(ss.substr(i,5));
            begin = i + 5;
            ll = 0;
            for ( int j = begin; j < length; j++){
                if ( ss[j] != '<') ll++;
                else break;
            }
            push(ss.substr(begin, ll));
            i = begin + ll;
            continue;
        }
        if ( ss.substr(i,2) == "<y"){
            push(ss.substr(i,8));
            begin = i + 8;
            ll = 0;
            for ( int j = begin; j < length; j++){
                if ( ss[j] != '<') ll++;
                else break;
            }
            push(ss.substr(begin, ll));
            i = begin + ll;
            continue;
        }

        if ( ss.substr(i,2) == "<b" ){
            push(ss.substr(i,6));
            begin = i + 6;
            ll = 0;
            for ( int j = begin; j < length; j++){
                if ( ss[j] != '<') ll++;
                else break;
            }
            push(ss.substr(begin, ll));
            i = begin + ll;
            continue;
        }
        if ( ss.substr(i,3) == "</r" ){
            while ( my_stack[height].substr(0,2) != "<r"){
                Note[0] += my_stack[height].length();
                pop();
            }
            i = i + 6;
            pop();
            continue;
        }
        if ( ss.substr(i,3) == "</y" ){
            while ( my_stack[height].substr(0,2) != "<y"){
                Note[1] += my_stack[height].length();
                pop();
            }
            pop();
            i = i + 9;
            continue;
        }
        if ( ss.substr(i,3) == "</b" ){
            while ( my_stack[height].substr(0,2) != "<b"){
                Note[2] += my_stack[height].length();
                pop();
            }
            pop();
            i = i + 7;
            continue;
        }

        for ( int k = height; k >=0; k--){
            if ( my_stack[k].substr(0,1) == "<")
                flag = 1;
        }
        if ( flag == 1 ){
            ll = 0;
            for ( int j = i; j < length; j++){
                if ( ss[j] != '<' ) ll++;
                else break;
            }
            if ( ll != 0 ){
                push(ss.substr(i, ll));
                i = i + ll;
            }
            continue;
        }
        else i++;
    }
}

int main()
{
    string s;
    while( cin>>s ){
        int Note[3] = {0};
        height = 0;
        for ( int i = 0; i < 100; i++){
            my_stack[i] = " ";
        }
        count(s, Note);
        cout<<Note[0]<<' '<<Note[1]<<' '<<Note[2]<<endl;
        //cout<<s<<endl;
    }
    //system("pause");
    return 0;
}
