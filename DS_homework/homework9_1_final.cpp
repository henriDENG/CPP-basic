#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int find_head(int *A, int l, int r)
{
    int mid = (l+r)/2;
    if ( A[mid] > A[l] )
        return find_head(A, l, mid);
    if ( A[mid] < A[l] )
        return find_head(A, mid, r);
    if ( l == r-1 )
        return r;
}

int bs(int *A, int l, int r, int t)
{
    int mid = (l+r)/2;
    if ( l > r )
        return -1;
    if ( t > A[mid] )
        return bs(A, l, mid-1, t);
    if ( t < A[mid] )
        return bs(A, mid+1, r, t);
    if ( t == A[mid] )
        return mid;
}

int find_target(int *A, int l, int r, int t, int head)
{

    if ( t == A[r] )
        return r;
    if ( t == A[l] )
        return l;
    if ( t == A[head] )
        return head;
    if ( t > A[head] )
        return -1;
    if ( t > A[r] ){
        return bs(A, head+1, r-1, t);
    }
    if ( t < A[r] ){
        return bs(A, l+1, head-1, t);
    }
}

int main()
{
   int N;
   cin>>N;
   for (int k = 0; k < N; k++){
        int A[100] = {0};
        int i;
        int length = 0;
        for(i = 0; ; i++){
            cin>>A[i];
            length++;
            if( getchar() =='\n' )
                break;
        }
        int head = -10;
        int target = -1;
        int index = -10;
        int ori_index = -10;
            if ( A[0] > A[length-1]){
                while ( cin>>target ){
                    index = bs(A, 0, length-1, target);
                    ori_index = index;
                    cout<<ori_index<<endl;
                    if ( getchar() == '\n' )
                        break;
                }
            }
            else{
                head = find_head(A, 0, length-1);
                //cout<<"index of head is: "<<head<<endl;
                while ( cin>>target ){
                    index = find_target(A, 0, length-1, target, head);
                    if ( index == -1 )
                        ori_index = -1;
                    else if ( index >= head )
                        ori_index = index - head;
                    else if ( index < head )
                        ori_index = length - head + index;
                    cout<<ori_index<<endl;
                    if ( getchar() == '\n' )
                        break;
                }
            }
    }
    //system("pause");
    return 0;
}
