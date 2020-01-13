#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

class Graph
{
private:
    int matrix_adj[26][26];
    int degree[26];
    int queue[26];
    int status;

public:
    Graph(){
        memset(matrix_adj, 0, sizeof(matrix_adj));
        memset(degree, 0, sizeof(degree));
        memset(queue, 0, sizeof(queue));
        status = 1;
    }
    Graph(int A[][26], int B[]){
        memset(matrix_adj, 0, sizeof(matrix_adj));
        for (int i = 0; i < 26; i++){
            for ( int j = 0; j < 26; j++){
                matrix_adj[i][j] = A[i][j];
            }
        }
        memset(degree, 0, sizeof(degree));
        for (int k = 0; k < 26; k++){
            degree[k] = B[k];
        }
        memset(queue, 0, sizeof(queue));
        status = 1;
    }
    ~Graph() {}
    void Topo_sorting(int n);
    bool judge(int i, int n);
    void show();
};

void Graph::show()
{
    for ( int i = 0; i < 26; i++){
        for ( int j = 0; j < 26; j++){
            cout<<matrix_adj[i][j]<<" ";
        }
        cout<<endl;
    }
    for ( int j = 0 ; j < 26; j++){
        cout<<degree[j]<<" ";
    }
    cout<<endl;
    for ( int k = 0; k < 26; k++){
        cout<<queue[k]<<" ";
    }
    cout<<endl;
    cout<<status<<endl;
}

void Graph::Topo_sorting(int n)
{
    int index = 0;
    int temp[26] = {0};
    int num_freepoints = 0;
    int pos;

    for ( int i = 0; i < 26; i++ ){
        temp[i] = degree[i];
    }

    for ( int i = 0; i < n; i++){
        num_freepoints = 0;
        for ( int j = 0; j < n; j ++ ){
            if ( temp[j] == 0){
                num_freepoints++;
                pos = j;
            }
        }
        if ( num_freepoints > 1)
            status = -1;
        if ( num_freepoints == 0){
            status = 0;
            break;
        }
        queue[index++] = pos;
        for ( int k = 0; k < n; k++ ){
            if ( matrix_adj[pos][k] == 1 )
                temp[k]--;
        }
        temp[pos] = -666;
    }
}

bool Graph::judge(int i, int n)
{
    if ( status == 0){
        cout<<"Inconsistency found after "<<i+1<<" relations."<<endl;
        return true;
    }
    if ( status == 1){
        cout<<"Sorted sequence determined after "<<i+1<<" relations: ";
        for ( int j = 0; j < n; j++ ){
            char ch = 'A' + queue[j];
            cout<<ch;
        }
        cout<<"."<<endl;
        return true;
    }
    else
        return false;
}

int main()
{
    int n,m;
    cin>>n>>m;
    string str;
    bool flag;
    while( n!= 0 && m != 0){
        int A[26][26] = {0};
        int B[26] = {0};
        flag = false;
        for ( int i = 0; i < m; i++){
            cin>>str;
            if ( flag == true )
                continue;
            int p = str[0]-'A';
            int q = str[2]-'A';
            A[p][q] = 1;
            B[q]++;
            Graph my_graph(A, B);
            my_graph.Topo_sorting(n);
            flag = my_graph.judge(i, n);
        }
        if ( flag == false )
            cout<<"Sorted sequence cannot be determined."<<endl;
        cin>>n>>m;
    }

    //system("pause");
    return 0;
}
