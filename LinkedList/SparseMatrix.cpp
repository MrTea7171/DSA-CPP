#include<iostream>
using namespace std;

struct node
{
    int col;
    int val;
    struct node * next;
};

void insertValue(struct node *A[])
{
    int row_val;
    struct node *t=new node;
    cout<<"Enter row, column and value:"<<endl;
    cin>>row_val>>t->col>>t->val;
    t->next=NULL;
    if(A[row_val]==NULL)
    {
        A[row_val]=t;
    }
    else
    {
        struct node *p=A[row_val];
        while (p->next || p->next->col<t->col)
        {
            p=p->next;
        }

        t->next=p->next;
        p->next=t;
        
    }
}

void create(struct node *A[], int row,int column)
{
    int elements;
    cout<<"Enter elements:"<<endl;
    cin>>elements;

    for (int i=0;i<row;i++)
    {
        A[i]=NULL;
    }

    for (int i=0;i<elements;i++)
    {
        insertValue(A);
    }
}

void display(struct node *A[], int row,int column)
{
    for(int i=0;i<row;i++)
    {
        struct node *t=NULL;
        if(A[i])
        {
            t=A[i];
        }
        for(int j=0;j<column;j++)
        {
            if(t && t->col==j)
            {
                cout<<t->val<<" ";
                t=t->next;
            }
            else
            {
                cout<<"0 ";
            }
        }

        cout<<endl;
    }

}

int main()
{
    int row,column;
    cout<<"Enter row:"<<endl;
    cin>>row;
    cout<<"Enter column:"<<endl;
    cin>>column;

    struct node * A[row];
    create(A,row,column);
    display(A,row,column);
    insertValue(A);
    display(A,row,column);

    return 0;
}