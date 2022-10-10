#include<iostream>
using namespace std;

class Element
{
    public:
        int row_no;
        int column_no;
        int data;
};

class Sparse
{
    private:
        int rows;
        int columns;
        int elements;
        Element *E;

    public:
    Sparse(int rows,int columns,int elements)
    {
        this->rows=rows;
        this->columns=columns;
        this->elements=elements;
        E=new Element[elements];
    }

    
    ~Sparse()
    {
        delete []E;
    }

    Sparse operator+(Sparse &s);
    friend istream & operator>>(istream &is,Sparse &s);
    friend ostream & operator<<(ostream &os,Sparse &s);
};

Sparse Sparse::operator+(Sparse &s)
{
    Sparse *sum=new Sparse(rows,columns,elements+s.elements);
    int i,j,k;
    i=j=k=0;

    sum->E=new Element[sum->elements];
    while(i<elements && j<s.elements)
    {
        if(E[i].row_no<s.E[j].row_no)
        {
            sum->E[k++]=E[i++];
        }
        else if(E[i].row_no>s.E[j].row_no)
        {
            sum->E[k++]=s.E[j++];
        }
        else if(E[i].column_no<s.E[j].column_no)
        {
            sum->E[k++]=E[i++];
        }
        else if(E[i].column_no>s.E[j].column_no)
        {
            sum->E[k++]=s.E[j++];
        }
        else
        {
            sum->E[k]=E[i];
            sum->E[k++].data=E[i++].data+s.E[j++].data;
        }
    }
    while(i<elements)
    {
        sum->E[k++]=E[i++];
    }
    while(j<s.elements)
    {
        sum->E[k++]=s.E[j++];
    }

    return *sum;
}

istream & operator>>(istream &is,Sparse &s)
{
    cout<<"Enter Non Zero Elements: "<<endl;
    for(int i=0;i<s.elements;i++)
    {
        cin>>s.E[i].row_no;
        cin>>s.E[i].column_no;
        cin>>s.E[i].data;
    }
}

ostream & operator<<(ostream &os,Sparse &s)
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


int main()
{
    Sparse s1(5,5,4),s2(5,5,3);
    cin>>s1;
    cin>>s2;
    cout<<endl;
    cout<<"Matrix A:"<<endl;
    cout<<s1;
    cout<<endl;
    cout<<"Matrix B:"<<endl;
    cout<<s2;
    cout<<endl;
    cout<<"Matrix Addition:"<<endl;
    Sparse s=s1+s2;
    cout<<s;
    return 0;
}