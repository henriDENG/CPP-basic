//用链表类写了一个，测试一下。之前一次是试析构函数
#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;

template <class T>
class Node
{
public:
    Node<T> *next;
    Node<T> *prev;
    T data;
    Node(){
        next = NULL;
        prev = NULL;
        data = 0;
    };
    Node(const Node &node){
        next = node.next;
        prev = node.prev;
        data = node.data;
    };
};

template <class T>
class List
{
private:
    Node<T> *head;
    Node<T> *tail;
    int length;
public:
    List();
    List(const List &LList);
    ~List();
    void add(T var);
    void Remove()
    void combination(const List &b);
    void show();
};

template<typename T>
List<T>::List()
{
    head = new Node<T>;
    tail = new Node<T>;
    head->data = 0;
    head->next = tail;
    head->prev = NULL;
    tail->data = 0;
    tail->next = NULL;
    tail->prev = head;
    length=0;
}

template<typename T>
List<T>::List(const List &LList)
{
    head = new Node<T>;
    tail = new Node<T>;
    head->data = 0;
    head->next = tail;
    head->prev = NULL;
    tail->data = 0;
    tail->next = NULL;
    tail->prev = head;
    length = 0;

    Node<T> *temp = LList.head;
    while(temp->next != LList.tail){
        temp = temp->next;
        tail->data = temp->data;
        Node<T> *p = new Node<T>;
        tail->next = p;
        p->prev = tail;
        tail = p;
        length++;
    }
    tail->next = NULL;
}


template<typename T>
List<T>::~List()
{
    delete head;
    delete tail;
    head = NULL;
    tail =NULL;
/*
    while(head->next != NULL) //Segmentation fault, 无法访问head->next
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
    delete head;
    head = NULL;
*/
}


template<typename T>
void List<T>::add(T var)
{
    tail->data = var;
    tail->next= new Node<T>;
    Node<T> *p = tail;
    tail = tail->next;
    tail->data = 0;
    tail->next = NULL;
    tail->prev = p;
    length++;
}

template<typename T>
void List<T>::combination(const List &b)
{
    Node<T> *p = b.head;
    Node<T> *q = b.tail;
    Node<T> *temp = tail->prev;
    temp->next = p->next;
   // cout<<"temp->next: "<<tail->next<<endl;//第一个节点指针
    p = p->next;
    p->prev = temp;
    tail = q;
    tail->next = NULL;
    tail->prev = q->prev;
    length += b.length;

}

template<typename T>
void List<T>::show()
{
    if (length == 0){
        cout<<"List is empty"<<endl;
    }
    Node<T> *p = head->next;
    //cout<<"head->next of b: "<<head->next<<endl;//第一个节点地址
    while (p != tail){
        cout<<p->data;
        p = p->next;
    }
    cout<<endl;
}

int main()
{
    int n;
    //scanf("%d\n",&n);
    cin>>n;
    getchar();
    for (int i=0;i<n;i++){
        List<char> List_a;
        List<char> List_b;
        char ch;
        ch = getchar();
        while( ch != '\n' ){
            List_a.add(ch);
            ch = getchar();
        }
        ch = getchar();
        while( ch != '\n'){
            List_b.add(ch);
            ch = getchar();
        }
        // List_a.show();
        //List_b.show();
        List_a.combination(List_b);
        List_a.show();
    }

    return 0;
}
