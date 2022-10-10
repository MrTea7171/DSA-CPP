#include<iostream>
#include<vector>
using namespace std;

struct node 
{
    int data;
    struct node *next;
}*first=NULL;

void createList(int Arr[],int n)
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

void sortedInsert(struct node *p,int k)
{
    struct node *t=new struct node;
    t->data=k;
    if(p->data>=k)
    {
        t->next=first;
        first=t;
    }
    else
    {
        while((p->next)->data<k)
        {
            p=p->next;
        }

        t->next=p->next;
        p->next=t;
    }
}

void displayList()
{
    struct node *t=first;
    while(t)
    {
        cout<<t->data<<endl;
        t=t->next;
    }
}

void deleteNode(struct node *p,int index)
{
    if(index==0)
    {
        struct node *toDelete=first;
        first=first->next;
        delete toDelete;
    }
    else
    {
        struct node *last=NULL;
        while(index!=0)
        {
            last=p;
            p=p->next;
            index--;
        }

        struct node *toDelete=p;
        last->next=p->next;
        delete toDelete;
    }
}

int checkSorted(struct node *p)
{
    while(p->next!=NULL)
    {
        if(p->data>(p->next)->data)
        {
            return false;
        }

        p=p->next;
    }

    return true;
}

void removeDuplicates(struct node *p)
{
    while(p->next!=NULL)
    {
        if(p->data==(p->next)->data)
        {
            struct node *t=p->next;
            p->next=t->next;
            delete t;
        }
        p=p->next;
    }
}

/*
//Reverse LinkList by data
void reverseElements(struct node *p)
{
    vector<int> elements;

    while(p)
    {
        elements.push_back(p->data);
        p=p->next;
    }

    p=first;
    while(p)
    {
        p->data=elements.back();
        elements.pop_back();
        p=p->next;
    }
    
}
*/

//Reverse LinkList by pointers
void reverseNext(struct node *p)
{
    struct node *q=NULL;
    struct node *r=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;

        q->next=r;
    }
    
    first=q;
}

/*
//Reverse LinkList Using Recursion
void recursiveReverseNext(struct node *p,struct node *q)
{
    if(p==NULL)
    {
        first=q;
        return;
    }
    struct node *r;
    r=q;
    q=p;
    p=p->next;
    q->next=r;
    recursiveReverseNext(p,q);
}
*/

int main()
{
    int Arr[]={3,7,9,9,15,20,20,21};
    createList(Arr,8);
    displayList();
    // cout<<endl<<endl<<endl<<endl;
    // cout<<"After Insertion"<<endl;
    // sortedInsert(first,4);
    // displayList();

    // cout<<endl<<endl<<endl<<endl;
    // cout<<"After Deletion"<<endl;
    // deleteNode(first,3);
    // displayList();

    cout<<checkSorted(first)<<endl;
    removeDuplicates(first);
    displayList();

    cout<<endl<<endl<<endl;
    cout<<"Reverse of LinkList"<<endl;
    //reverseElements(first);
    reverseNext(first);
    //recursiveReverseNext(first,NULL);
    displayList();

    return 0;
}