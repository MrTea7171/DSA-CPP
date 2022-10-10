#include<iostream>
#include<vector>
using namespace std;

struct node 
{
    int data;
    struct node *next;
};

void createList(int Arr[],int n,struct node *&first)
{
    struct node *t=new struct node;
    struct node *last;
    t->data=Arr[0];
    t->next=first;
    first=t;
    last=t;
    for(int i=1;i<n;i++)
    {
        struct node *t=new struct node;
        t->data=Arr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void displayList(struct node *t)
{
    while(t)
    {
        cout<<t->data<<endl;
        t=t->next;
    }
}

void concatList(struct node *p,struct node *q)
{
    while(p->next)
    {
        p=p->next;
    }
    p->next=q;
}

struct node * mergeList(struct node *p,struct node *q)
{
    struct node *third=NULL;
    struct node *last=NULL;
    if(p->data>q->data)
    {
        third=last=q;
        q=q->next;
        last->next=NULL;
    }
    else
    {
        third=last=p;
        p=p->next;
        last->next=NULL;
    }
    while(p && q)
    {
        if(p->data>q->data)
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
        else
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
    }

    while(p)
    {
        last->next=p;
        last=p;
        p=p->next;
        last->next=NULL;
    }

    while(q)
    {
        last->next=q;
        last=q;
        q=q->next;
        last->next=NULL;
    }

    return third;
}

int main()
{
    struct node *first=NULL;
    struct node *second=NULL;
    int Arr1[]={2,4,6,8};
    int Arr2[]={3,7,10};

    //Create List
    createList(Arr1,4,first);
    createList(Arr2,3,second);

    //Display List
    cout<<"List 1:"<<endl;
    displayList(first);
    cout<<endl;
    cout<<"List 2:"<<endl;
    displayList(second);

    //Concat
    /*
    concatList(first,second);
    cout<<endl;
    cout<<"After Concat:"<<endl;
    displayList(first);
    */

    cout<<endl;
    cout<<"After Merge:"<<endl;
    first=second=mergeList(first,second);
    displayList(first);
    return 0;
}