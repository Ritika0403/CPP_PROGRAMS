#include<iostream>
using namespace std;
class doubly;
class Node
{
    int data;
    Node* next;
    Node* prev;
    public:
        Node();
        friend class doubly;
        
        
};
class doubly
{
    Node* head;
    Node* tail;
    public:
        doubly();
        friend class Node;
        Node* create(int);
        void append(int);
        void addbeg(int);
        void insertbefore(int,int);
        void insertafter(int,int);
        void deleteany(int);
        void deletebeg();
        void deletend();
        void display();
        friend ostream& operator<<(ostream&,Node);
        friend istream& operator>>(istream&,Node);
};
Node::Node()
{
    data = 0;
    next = NULL;
    prev = NULL;
}
doubly::doubly()
{
    head = NULL;
    tail = NULL;
}
Node* doubly::create(int val)
{
    Node* temp = new Node();
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void doubly::append(int val)
{
    Node* newnode = create(val);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
}
void doubly::addbeg(int val)
{
    Node* newnode = create(val);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}
void doubly::insertbefore(int val,int pos)
{
    Node* newnode = create(val);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    Node* current = head;
    pos = pos - 1;
    while(pos--)
        current = current->next;
    Node* temp = current->next;
    current->next = newnode;
    newnode->prev = current;
    newnode->next = temp;
    temp->prev = newnode; 
}
void doubly::insertafter(int val,int pos)
{
    Node* newnode = create(val);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    Node* current = head;
    while(pos--)
        current = current->next;
    Node* temp = current->next;
    current->next = newnode;
    newnode->prev = current;
    newnode->next = temp;
    temp->prev = newnode; 
}
void doubly::display()
{
    Node* current = head;
    while(current != NULL)
    {
        cout<<current->data<<" ";
        current = current->next;
    } 
    cout<<endl;
}
void doubly:: deleteany(int pos)
{
    Node* current = head;
    while(pos--)
    {
        current = current->next;
    }
    current->next = current->next->next;
    current->next->prev = current;
}
void doubly:: deletebeg()
{
    head = head->next;
    head->prev = NULL;
}
void doubly:: deletend()
{
    tail = tail->prev ;
    tail->next = NULL;
}
int main()
{
    doubly ll;
    ll.append(1);
    ll.append(2);
    ll.append(3);
    ll.append(4);
    ll.addbeg(5);
    ll.insertafter(20,3);
    ll.insertbefore(20,2);
    ll.display();
    ll.deleteany(3);
    ll.display();
    ll.deletebeg();
    ll.deletend();
    ll.display();
    return 0;
}