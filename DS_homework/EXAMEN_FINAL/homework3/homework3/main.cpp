#include<iostream>
#include<cstdio>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int& x)
    {
        data = x;
        next = NULL;
    }
};

class Linklist
{
private:
    Node* head;
    Node* tail;
    Node* fence1;
    Node* fence2;
public:
    Linklist()
    {
        head = new Node;
        tail = new Node;
        head->next = tail;
        fence1 = NULL;
        fence2 = NULL;
    }
    ~Linklist()
    {
        Node* p = head->next;
        while( p != NULL){
            Node* temp = p;
            p = p->next;
            delete temp;
        }
        delete head;
    }
    void Add(int x);
    void Partition(int x);
    void Show();
};

void Linklist::Add(int x)
{
    tail->data = x;
    tail->next = new Node;
    tail = tail->next;
}

void Linklist::Partition(int x)
{
    Node* first_of_a = NULL;
    Node* first_of_b = NULL;
    Node* last_of_a = NULL;
    Node* last_of_b = NULL;

    Node* temp = head->next;
    Node* p = temp->next;

    if ( temp->data < x){
        first_of_a = temp;
        fence1 = temp;
        while ( p != tail ){
            if ( p->data < x ){
                fence1 = p;
                p = p->next;
            }
            else{
                first_of_b = p;
                fence2 = p;
                break;
            }
        }
    }
    else{
        first_of_b = temp;
        fence2 = temp;
        while ( p != tail ){
            if ( p->data >= x){
                fence2 = p;
                p = p->next;
            }
            else{
                first_of_a = p;
                fence1 = p;
                head->next = first_of_a;
                break;
            }
        }
    }

    // 可能一路走到最后，本来就是排好序的
    if ( p != tail ){
        p = p->next;
        while ( p != tail ){
            if ( p->data < x){
                fence1->next = p;
                fence1 = fence1->next;
                p = p->next;
            }
            else{
                fence2->next = p;
                fence2 = fence2->next;
                p = p->next;
            }
        }

        last_of_a = fence1;
        last_of_b = fence2;
        if ( last_of_a->next != tail ){
            last_of_a->next = first_of_b;
        }
        else{
            last_of_a->next = first_of_b;
            last_of_b->next = tail;
        }
    }
}

void Linklist::Show()
{
    Node* p = head->next;
    while ( p != tail ){
        if ( p == head->next){
            cout<<p->data;
            p = p->next;
        }
        else{
            cout<<" "<<p->data;
            p = p->next;
        }
    }
    cout<<endl;
}

int main()
{
    int N;
    int num;
    int x;
    cin>>N;
    //getchar();
    for ( int i = 0; i < N; i++ ){
        Linklist LList;
        while( cin>>num ){
            LList.Add(num);
            if ( cin.get() == '\n') break;
        }
        cin>>x;
        LList.Partition(x);
        LList.Show();
    }
    return 0;
}
