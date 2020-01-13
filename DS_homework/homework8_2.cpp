#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

class minheap
{
private:
    long int max_size;
    long int curr_size;
    long int total_size;
    long int* heap;
    void swap(long int a, long int b){
        long int temp;
        temp = heap[a];
        heap[a] = heap[b];
        heap[b] = temp;
    }
    void sift_down(long int index){
        long int lc;
        long int rc;
        long int sc;
        long int lc_index = 2*index+1;
        long int rc_index = 2*index+2;
        long int sc_index;
        long int temp = 0;

        while ( lc_index < curr_size ){
            temp = heap[index];
            lc = heap[lc_index];
            if ( rc_index < curr_size && lc > heap[rc_index]){
                rc = heap[rc_index];
                sc = rc;
                sc_index = rc_index;
            }
            else{
                sc = lc;
                sc_index = lc_index;
            }
            if (temp > sc){
                swap(index,sc_index);
                index = sc_index;
                lc_index = index*2+1; //更新
                rc_index = index*2+2;
            }
            else break;
        }
    } //基于任意堆一次重整一个pass, 往下沉
    void sift_up(long int index){
        long int temp = heap[index];
        long int par_index = (index-1)/2;
        long int par = heap[par_index];
        while (index > 0){
            if (temp < par){
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
    minheap(){
        max_size = 1000;
        curr_size = 0;
        total_size = 0;
        heap = new long int[max_size];
        for(long int i = 0; i <= max_size; i++){
            heap[i] = 0;
        }
    }
    minheap(const long int* arr, const long int k, const long int l){
        max_size = 1000;
        curr_size = k;
        total_size = l;
        heap = new long int[max_size];
        for (long int i = 0; i < curr_size; i++){
            heap[i] = arr[i];
        }
        for(long int j = curr_size/2-1; j >= 0; j--){
            sift_down(j);
        }
    }
    ~minheap(){
        delete []heap;
        heap = NULL;
        curr_size = 0;
    }
    void k_biggest(long int* k);
    void show();
};

void minheap::k_biggest(long int* d)
{
    long int temp = *d;
    if (temp > heap[0]){
        heap[0] = temp;
        sift_down(0);
    }
}

void minheap::show()
{
    cout<<heap[0]<<endl;
}

int main()
{
    long int arr[1000] = {0};
    long int l = 0;
    long int k = 0;
    long int d = 0;
    cin>>l>>k;
    for (long int i = 0; i < k; i++){
        cin>>arr[i];
    }
    minheap h(arr,k,l);
    for (long int i = k; i < l; i++){
        cin>>d;
        h.k_biggest(&d);
    }
    h.show();
    return 0;
}
