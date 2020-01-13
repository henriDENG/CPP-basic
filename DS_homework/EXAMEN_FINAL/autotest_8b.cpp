#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<cmath>

using namespace std;

int hashing(string s)
{
    double val = 0;
    int l = s.size();
    for ( int i = 0; i < l; i++ ){
        val += s[i] * s[i] + s[i] * pow(2, i);
    }
    val = (int) val;
    return val;
}

vector<string> find_repeated_DNA(string s)
{
    int l = s.size();
    string ss;
    int temp = -1;
    vector<string> v;
    map<int,int> s_map;

    if ( l > 10 ){
        for ( int i = 0; i < l - 9; i++ ){
            ss = s.substr(i, 10);
            temp = hashing(ss);
            if ( s_map.find(temp) == s_map.end() )
                s_map[temp] = 1;
            else if ( s_map.find(temp) != s_map.end() && s_map[temp] == 1 ){
                v.push_back(ss);
                s_map[temp]++;
            }
            else if ( s_map.find(temp) != s_map.end() && s_map[temp] > 1 )
                s_map[temp]++;
        }
    }
    else {}
    return v;
}

int main()
{
    int N;
    cin>>N;
    for ( int i = 0; i < N; i++ ){
        string s;
        cin>>s;
        cout<<s.size()<<endl;
        vector<string> result;
        result = find_repeated_DNA(s);
        cout<<"[";
        for ( int j = 0; j < result.size(); j++ ){
            if ( j != result.size() - 1 )
                cout<<result[j]<<",";
            else
                cout <<result[j];
        }
        cout<<"]"<<endl;
    }
    return 0;
}
