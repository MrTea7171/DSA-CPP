#include<iostream>
using namespace std;

void Insert(int A[],int n)
{
    int i=n,temp;
    temp=A[i];

    while(i>1 && temp>A[i/2])
    {
        A[i]=A[i/2];
        i/=2;
    }
    A[i]=temp;
}

int Delete(int A[],int n)
{
    int i,j,x;
    x=A[1];
    i=1;
    j=2*i;
    A[1]=A[n];
    A[n]=x;

    while(j<n-1)
    {
        if(A[j]<A[j+1])
        {
            j++;
        }
        if(A[i]<A[j])
        {
            swap(A[i],A[j]);
            i=j;
            j=i*2;
        }
        else
        {
            break;
        }

    }

    return x;

}

void Display(int H[],int n)
{
    for(int i=1;i<n;i++)
    {
        cout<<H[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int H[]={0,2,5,8,9,4,10,7};
    for(int i=2;i<8;i++)
    {
        Insert(H,i);
    }
    Display(H,8);
    for(int i=7;i>1;i--)
    {
        Delete(H,i);
    }
    Display(H,8);
    return 0;
}