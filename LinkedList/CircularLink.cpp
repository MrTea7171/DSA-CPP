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
        t->next=first;
        last->next=t;
        last=t;
    }
}

void displayList(struct node *t)
{
    struct node *start=t;
    do
    {
        cout<<t->data<<endl;
        t=t->next;
    }while(t!=start);
}

void insertNode(struct node *&start,int key,int index)
{
    struct node *t=start;
    if(index==0)
    {
        do
        {
            t=t->next;
        }while(t->next!=start);
        struct node *new_node=new struct node;
        new_node->data=key;
        new_node->next=t->next;
        t->next=new_node;
        start=new_node;
    }
    else
    {
        int count=0;
        while(count!=index-1)
        {
            count++;
            t=t->next;
        }
        struct node *new_node=new struct node;
        new_node->data=key;
        new_node->next=t->next;
        t->next=new_node;
    }

}

void deleteNode(struct node *&start,int index)
{
    struct node *t=start;
    if(index==0)
    {
        do
        {
            t=t->next;
        }while(t->next!=start);
        t->next=start->next;
        t=start;
        start=start->next;
        delete t;
    }
    else
    {
        int count=0;
        while(count!=index-1)
        {
            count++;
            t=t->next;
        }
        struct node *remove=t->next;
        t->next=(t->next)->next;
        delete remove;
    }

}

/*

//Display List Recursively
void recursiveDisplayList(struct node *t)
{
    static struct node *start=t;
    static int flag=0;

    if(t!=start || flag==0)
    {
        flag=1;
        cout<<t->data<<endl;
        recursiveDisplayList(t->next);
    }

    flag=0;
    
}
*/

int main()
{
    struct node *first=NULL;
    int Arr1[]={2,4,6,8};

    //Create List
    createList(Arr1,4,first);
    displayList(first);
    //recursiveDisplayList(first);
    cout<<endl<<endl<<endl;
    cout<<"After Insert:"<<endl;
    insertNode(first,5,3);
    displayList(first);

    cout<<endl<<endl<<endl;
    cout<<"After delete:"<<endl;
    deleteNode(first,2 );
    displayList(first);
    return 0;
}