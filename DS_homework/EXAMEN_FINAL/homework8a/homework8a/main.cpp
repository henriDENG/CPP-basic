#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int find_head(int *A, int l, int r)
{
    int mid = (l+r)/2;
    if ( A[mid] > A[l] ) return find_head(A, l, mid);
    if ( A[mid] < A[l] ) return find_head(A, mid, r);
    if ( l == r - 1) return r;
}

int bs(int *A, int l, int r, int t)
{
    int mid = (l+r)/2;
    if ( l > r ) return -1;
    if ( A[mid] > t ) return bs(A, mid+1, r, t);
    if ( A[mid] < t ) return bs(A, l, mid-1, t);
    if ( A[mid] == t ) return mid;
}

int find_target(int *A, int l, int r, int t, int head)
{
    if ( t > A[head] ) return -1;
    if ( A[l] == t ) return l;
    if ( A[r] == t ) return r;
    if ( A[head] == t ) return head;
    if ( t < A[r] ) return bs(A, l+1, head-1, t);
    if ( t > A[r] ) return bs(A, head+1, r-1, t);
}

int main()
{
    int N;
    cin>>N;
    for ( int i = 0; i < N; i++ ){
        int A[100] = {0};
        int l = 0;
        int j;
        for ( j = 0; ; j++ ){
            cin>>A[j];
            l++;
            if ( getchar() == '\n') break;
        }
        int target = -10;
        int index = -10;
        int ori_index = -10;
        int head = -10;
        if ( A[0] > A[l-1] ){
            while( cin>>target ){
                index = bs(A, 0, l-1, target);
                ori_index = index;
                cout<<ori_index<<endl;
                if ( getchar() == '\n' ) break;
            }
        }
        else{
            head = find_head(A, 0, l-1);
            while ( cin>>target ){
                index = find_target(A, 0, l-1, target, head);
                if ( index == -1 ) ori_index = -1;
                else if ( index >= head ) ori_index = index - head;
                else ori_index = l - head + index;
                cout<<ori_index<<endl;
                if ( getchar() == '\n') break;
            }
        }
    }
    return 0;
}
