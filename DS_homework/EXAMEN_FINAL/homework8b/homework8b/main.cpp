#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<cmath>

using namespace std;

int hashing(string s)
{
    int l = s.size();
    double val = 0;
    for ( int i = 0; i < l; i++ ){
        val += s[i]*s[i] + s[i] * pow(2,i);
    }
    val = int (val);
    return val;
}

vector<string> find_repeat_DNA(string s)
{
    int l;
    int temp = -1;
    map <int,int> s_map;
    vector<string> v;
    string ss;
    l = s.size();
    if ( l < 10 ) return v;

    for ( int i = 0 ; i < l - 9; i++){
        ss = s.substr(i, 10);
        temp = hashing(ss);
        if ( s_map.find(temp) == s_map.end() ){
            s_map[temp] = 1;
        }
        else if ( s_map.find(temp) != s_map.end() && s_map[temp] == 1 ){
            s_map[temp]++;
            v.push_back(ss);
        }
        else if ( s_map.find(temp) != s_map.end() && s_map[temp] > 1){
            s_map[temp]++;
        }
    }
    return v;
}

int main()
{
    int N;
    cin>>N;
    int i;
    for ( i = 0; i < N; i++ ){
        string s;
        cin>>s;
        vector<string> result;
        result = find_repeat_DNA(s);
        cout<<"[";
        for ( int i = 0; i < result.size(); i++ ){
            if ( i != result.size() - 1 ){
                cout<<result[i]<<",";
            }
            else{
                cout<<result[i];
            }
        }
        cout<<"]"<<endl;
    }

    return 0;
}
