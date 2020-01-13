#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

class maxheap
{
private:
    int max_size;
    int curr_size;
    long int* heap;
    void swap(int a, int b){
        long int temp;
        temp = heap[a];
        heap[a] = heap[b];
        heap[b] = temp;
    }
    void sift_down(int index){
        long int lc;
        long int rc;
        long int bc;
        int lc_index = 2*index+1;
        int rc_index = 2*index+2;
        int bc_index;
        long int temp = 0;

        while ( lc_index < curr_size ){
            temp = heap[index];
            lc = heap[lc_index];
            if ( rc_index < curr_size && lc < heap[rc_index]){
                rc = heap[rc_index];
                bc = rc;
                bc_index = rc_index;
            }
            else{
                bc = lc;
                bc_index = lc_index;
            }
            if (temp < bc){
                swap(index,bc_index);
                index = bc_index;
                lc_index = index*2+1; //更新
                rc_index = index*2+2;
            }
            else break;
        }
    } //基于任意堆一次重整一个pass, 往下沉
    void sift_up(int index){
        long int temp = heap[index];
        int par_index = (index-1)/2;
        long int par = heap[par_index];
        while (index > 0){
            if (temp > par){
                swap(index, par_index);
                index = par_index;
                temp = heap[index];
                par_index = (index-1)/2;
                par = heap[par_index];
            }
            else break;
        }
    } //基于最大堆一次重整一个pass，往上浮
public:
    maxheap(){
        max_size = 100;
        curr_size = 0;
        heap = new long int[max_size];
        for(int i = 0; i <= max_size; i++){
            heap[i] = 0;
        }
    }
    maxheap(const long int* arr, const long int l){
        max_size = 100;
        curr_size = l;
        heap = new long int[max_size];
        for (int i = 0; i < curr_size; i++){
            heap[i] =arr[i];
        }
        for(int j = curr_size/2-1; j >= 0; j--){
            sift_down(j);
        }
    }
    ~maxheap(){
        delete []heap;
        heap = NULL;
        curr_size = 0;
    }
    void push(const long int val);
    void pop();
    void show();
};

void maxheap::push(const long int val)
{
    if (curr_size < max_size){
        heap[curr_size] = val;
        curr_size++;
        sift_up(curr_size-1);
    }
    else cout<<"heap is full"<<endl;
}

void maxheap::pop()
{
    if (curr_size > 0){
        swap(0,curr_size-1);
        curr_size--;
        sift_down(0);
    }
    else cout<<"heap is empty"<<endl;
}

void maxheap::show()
{
    cout<<heap[0]<<endl;
    /*for (int i=0;i<curr_size;i++){
        cout<<heap[i]<<' ';
    }*/
}

int main()
{
    int N;
    cin>>N;
    for (int j = 0; j < N; j++){
        int l = 0;
        int m = 0;
        cin>>l>>m;
        long int arr[100] = {0};
        for (int i = 0; i<l; i++){
            cin>>arr[i];
        }
        maxheap h(arr,l);
        for (int i = 0; i < m; i++){
            char ch;
            long int val = 0;
            cin>>ch;
            if (ch == 'I'){
                getchar();
                cin>>val;
                h.push(val);
                h.show();
            }
            else if (ch == 'P'){
                h.pop();
                h.show();
            }
        }
    }
    //system("pause");
    return 0;
}
