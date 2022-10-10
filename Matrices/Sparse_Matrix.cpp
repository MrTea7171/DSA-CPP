#include<iostream>
using namespace std;

struct Element
{
    int row_no;
    int column_no;
    int data;
};

struct Sparse
{
    int rows;
    int columns;
    int elements;
    struct Element *E;
};

void create(struct Sparse *s)
{
    cout<<"Enter rows and columns: "<<endl;
    cin>>s->rows>>s->columns;
    cout<<"Enter number of elements: "<<endl;
    cin>>s->elements;
    s->E=new struct Element[s->elements];
    cout<<"Enter Non Zero Elements: "<<endl;
    for(int i=0;i<s->elements;i++)
    {
        cin>>s->E[i].row_no;
        cin>>s->E[i].column_no;
        cin>>s->E[i].data;
    }
    
}

void display(struct Sparse s)
{
    int k=0;
    for(int i=1;i<=s.rows;i++)
    {
        for(int j=1;j<=s.columns;j++)
        {
            if(s.E[k].row_no==i && s.E[k].column_no==j)
            {
                cout<<s.E[k++].data<<" ";
            }
            else
            {
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
}

struct Sparse *add(struct Sparse *s1, struct Sparse *s2)
{
    struct Sparse *sum;
    sum=new struct Sparse;

    int i,j,k;
    i=j=k=0;

    sum->E=new struct Element[s1->elements+s2->elements];
    while(i<s1->elements && j<s2->elements)
    {
        if(s1->E[i].row_no<s2->E[j].row_no)
        {
            sum->E[k++]=s1->E[i++];
        }
        else if(s1->E[i].row_no>s2->E[j].row_no)
        {
            sum->E[k++]=s2->E[j++];
        }
        else if(s1->E[i].column_no<s2->E[j].column_no)
        {
            sum->E[k++]=s1->E[i++];
        }
        else if(s1->E[i].column_no>s2->E[j].column_no)
        {
            sum->E[k++]=s2->E[j++];
        }
        else
        {
            sum->E[k]=s1->E[i];
            sum->E[k++].data=s1->E[i++].data+s2->E[j++].data;
        }
    }
    while(i<s1->elements)
    {
        sum->E[k++]=s1->E[i++];
    }
    while(j<s2->elements)
    {
        sum->E[k++]=s2->E[j++];
    }

    sum->columns=s1->columns;
    sum->rows=s1->rows;
    sum->elements=k;
    return sum;
}

int main()
{
    struct Sparse s1,s2;
    struct Sparse *s;
    create(&s1);
    display(s1);
    create(&s2);
    display(s2);
    s=add(&s1,&s2);
    cout<<endl;
    cout<<"Matrix A:"<<endl;
    display(s1);
    cout<<endl;
    cout<<"Matrix B:"<<endl;
    display(s2);
    cout<<endl;
    cout<<"Matrix Addition:"<<endl;
    display(*s);
    return 0;
}