#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>

using namespace std;

int hashing(string s)
{
    int l = s.size();
    double temp = 0;
    for ( int i = 0; i < l; i++ ){
        temp += s[i] * s[i] + s[i] * pow(2, i);
    }
    temp = (int)temp;
    return temp;
}

vector<string> find_repeated_DNA(string s)
{
    map<int,int> s_map;
    vector<string> v;
    int temp;
    int length = s.size();

    if ( length < 10 ) return v;

    for ( int i = 0; i < length - 9; i++){
        string ss = s.substr(i,10);
        //cout<<ss<<endl;
        temp = hashing(ss);
        //cout<<temp<<endl;
        if ( s_map.find(temp) == s_map.end() ){
            s_map[temp] = 1;
        }

        else if ( s_map.find(temp) != s_map.end() && s_map[temp] == 1 ){
            s_map[temp]++;
            v.push_back(ss);
        }

        else if ( s_map.find(temp) != s_map.end() && s_map[temp] > 1 )
            s_map[temp]++;
    }
    return v;
}

int main()
{
    int N;
    cin>>N;
    for ( int i = 0; i < N; i++ ){
        string s;
        cin>>s;
        vector<string> result;
        result = find_repeated_DNA(s);
        cout<<"[";
        for ( int j = 0; j < result.size(); j++ ){
            if ( j != result.size() - 1)
                cout<<result[j]<<",";
            else
                cout<<result[j];
        }
        cout<<"]";
        cout<<endl;
    }

    return 0;
}
