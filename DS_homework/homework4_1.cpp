#include<iostream>
#include<cstring>
#include<stdio.h>

using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(){
        data = 0;
        next = NULL;
    };
    Node(T& x) : data(x), next(NULL) {}
};

template <class T>
class Linklist
{
private:
    Node<T> *head;
    Node<T> *tail;
    Node<T> *fence1;
    Node<T> *fence2;
    void init()
    {
        head = new Node<T>;
        tail = new Node<T>;
        fence1 = fence2 = NULL;
        head->data = 0;
        head->next = tail;
        tail->data = 0;
        tail->next = NULL;
    };
    void removeALL()
    {
        while(head->next != NULL){
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
        delete head;
        head = NULL;
    }

public:
    Linklist() {init();}
    ~Linklist() {removeALL();}
    void Clear() {
        removeALL();
        init();
    }
    void add(T var);
    void show();
    void partition(int x);
};

template <typename T>
void Linklist<T>::add(T var)
{
    tail->data = var;
    tail->next = new Node<T>;
    tail = tail->next;
    tail->data = 0;
    tail->next = NULL;
}

template<typename T>
void Linklist<T>::show()
{
    Node<T> *p = head->next;
    if ( p == tail){}
    else{
        cout<<p->data;
        p = p->next;
    }
    while(p != tail){
        cout<<' '<<p->data;
        p = p->next;
    }
    cout<<endl;
}

template<typename T>
void Linklist<T>::partition(int x)
{
    Node<T> *first_of_a;
    Node<T> *last_of_a;
    Node<T> *first_of_b;
    Node<T> *last_of_b;

    Node<T> *temp = head->next;
    Node<T> *p = temp->next;

    if ( temp->data < x){
        fence1 = temp;
        first_of_a = temp;

        while ( p != tail){
            if ( p->data < x){
                fence1 = p;
                p = p->next;
            }
            else{
                fence2 = p;
                first_of_b = fence2;
                break;
            }
        }
    }

    else if ( temp->data >= x){
        fence2 = temp;
        first_of_b = fence2;

        while ( p != tail){
            if( p->data >= x){
                fence2 = p;
                p = p->next;
            }
            else{
                fence1 = p;
                head->next = fence1;
                first_of_a = fence1;
                break;
            }
        }
    }

    if ( p == tail) {}
    else{
        p = p->next;
         while ( p != tail){
            if ( p->data < x ){
                fence1->next = p;
                fence1 = p;
                p = p->next;
            }
            else{
                fence2->next = p;
                fence2 = p;
                p = p->next;
            }
        }

        last_of_a = fence1;
        last_of_b = fence2;

        if (last_of_a->next != tail)
            last_of_a->next = first_of_b;
        else{
            last_of_b->next = tail;
            last_of_a->next = first_of_b;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    getchar();

    for(int i=0;i<n;i++){
        Linklist<int> List_a;
        int var;
        while( cin>>var ){
            List_a.add(var);
            if (cin.get() == '\n') break;
        }
        int x;
        cin>>x;
        getchar();
        //cout<<x<<endl;
        List_a.partition(x);
        List_a.show();
        List_a.Clear();

    }

    return 0;
}
