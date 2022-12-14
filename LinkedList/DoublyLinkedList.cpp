#include<iostream>
using namespace std;

struct node{
    struct node* prev;
    struct node* next;
    int data;
}*first=NULL;

void create(int A[],int n)
{
    struct node *t,*last;

    first=new node;
    first->prev=NULL;
    first->next=NULL;
    first->data=A[0];

    last=first;

    for(int i=1;i<n;i++)
    {
        t=new node;
        t->prev=last;
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}


//Min Time:Const || MaxTime:n
void insertNode(int value,int position)
{
    struct node* t=new node;
    t->data=value;

    if(position==0)
    {
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else
    {
        int count=0;
        struct node *p=first;
        while(count!=position)
        {
            count++;
            p=p->next;
        }

        t->next=p;
        t->prev=p->prev;
        if(p->prev)
        {
            p->prev->next=t;
        }
        p->prev=t;
    }
}

void deleteNode(int position)
{
    struct node* p;
    int data;
    if(position==0)
    {
        p=first;
        first=first->next;
        data=p->data;
        delete p;
        if(first)
        {
            first->prev=NULL;
        }
    }
    else
    {
        int count=0;
        struct node *p=first;
        while(count!=position)
        {
            count++;
            p=p->next;
        }
        data=p->data;
        p->prev->next=p->next;
        if(p->next)
        {
            p->next->prev=p->prev;
        }
        delete p;
    }

    cout<<data<<" has been deleted"<<endl;
}

void reverseList()
{
    struct node*p=first;
     while(p)
     {
        struct node* t;
        t=p->prev;
        p->prev=p->next;
        p->next=t;
        p=p->prev;

        if(p->next==NULL)
        {
            first=p;
        }
     }


}

void displayAsc()
{
    struct node*p=first;
    while(p)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
    cout<<endl;
}

int listLength()
{
    struct node*p=first;
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}

int main()
{
    int A[]={10,20,30,40,50};
    create(A,5);
    //insertNode(4,0);
    //displayAsc();
    insertNode(8,3);
    displayAsc();
    // deleteNode(0);
    // displayAsc();
    // deleteNode(3);
    // displayAsc();
    // insertNode(12,6);
    // displayAsc();
    reverseList();
    displayAsc();
    cout<<"Length of Link List:"<<(listLength())<<endl;
    return 0;
}