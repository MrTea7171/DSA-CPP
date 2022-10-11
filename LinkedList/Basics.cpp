#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
}*first=NULL;

void createList(int Arr[],int n)
{
    struct node* t;
    struct node* last;
    first=new struct node;
    first->data=Arr[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=new struct node;
        t->data=Arr[i];
        t->next=NULL;
        last->next=t;
        last=t;
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

int countList(struct node *t)
{
    int count=0;
    while(t)
    {
        count++;
        t=t->next;
    }
    return count;
}

int sumList(struct node *t)
{
    int sum=0;
    while(t)
    {
        sum+=t->data;
        t=t->next;
    }
    return sum;
}

int maxInList(struct node *t)
{
    int max=t->data;
    while(t)
    {
        if(max<t->data)
        {
            max=t->data;
        }
        t=t->next;
    }
    return max;
}

struct node * searchList(struct node * t,int key)
{
    while(t)
    {
        if(t->data==key)
        {
            return t;
        }
        t=t->next;
    }

    return NULL;
}

void pushElement(int index,int k)
{
    struct node * t=new struct node;
    t->data=k;
    if(index==0)
    {
        t->next=first;
        first=t;
        return;
    }
    int count=0;
    struct node *p=first;
    while(count!=index-1 && index>0)
    {
        p=p->next;
        count++;
    }
    t->next=p->next;
    p->next=t;
}

/*
struct node * optimzedSearchList(struct node * t,int key)
{
    struct node * last=NULL;
    while(t)
    {
        if(t->data==key)
        {
            last->next=t->next;
            t->next=first;
            first=t;
            return first;
        }
        last=t;
        t=t->next;
    }

    return NULL;
}

*/

/*
//Display Recursively
void recursiveDisplayList(struct node * t)
{
    if(t==NULL)
        return;
    
    cout<<t->data<<endl;
    recursiveDisplayList(t->next);
}
*/

/*
//Count Recursively
int recursiveCountList(struct node * t)
{
    if(t==NULL)
        return 0;

    return 1 + recursiveCountList(t->next);
}
*/

/*
//Sum Recursively
int recursiveSumList(struct node * t)
{
    if(t==NULL)
        return 0;

    return t->data + recursiveSumList(t->next);
}
*/

/*
//Max Recursively
int recursiveMaxInList(struct node * t)
{
    if(t==NULL)
        return INT8_MIN;
    int num=recursiveMaxInList(t->next);
    return (num>t->data)?num:t->data;
}
*/

/*
//RecursiveSearch
struct node *recursiveSearchList(struct node * t,int key)
{
    if(!t)
        return NULL;

    if(t->data==key)
    {
        return t;
    }
    return recursiveSearchList(t->next,key);
}
*/

int listMid(struct node * t)
{
    struct node *p, *q;
    p=q=t;
    while(q)
    {
        q=q->next;
        if(q)
        {
            q=q->next;
            p=p->next;
        }
    }

    return p->data;
}

int main()
{
    int A[]={4,9,7,8,6,0,2};
    createList(A,7);
    // int i=0;
    // while(i<7)
    // {
    //     pushElement(i,A[i]);
    //     i++;
    // }
    //displayList();
    // cout<<"Count is: "<<countList(first)<<endl;
    // cout<<"Sum is: "<<sumList(first)<<endl;
    // cout<<"Max Element in List : "<<maxInList(first)<<endl;
    // cout<<"Searching 9 in list : "<<searchList(first,9)<<endl;
    // pushElement(7,12);
    // displayList();
    cout<<"Output:"<<listMid(first)<<endl;
    //cout<<"Searching 9 in list : "<<optimzedSearchList(first,9)<<endl;
    //displayList();
    //recursiveDisplayList(first);
    //cout<<"Count is: "<<recursiveCountList(first)<<endl;
    //cout<<"Sum is: "<<recursiveSumList(first)<<endl;
    //cout<<"Max Element in List : "<<recursiveMaxInList(first)<<endl;
    //cout<<"Searching 9 in list : "<<recursiveSearchList(first,9)<<endl;
    return 0;
}