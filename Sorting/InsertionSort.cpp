#include<iostream>
using namespace std;

void InsertionSort(int H[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(H[j]<H[j-1])
                swap(H[j],H[j-1]);
            else
                break;
        }
    }
}

void Display(int H[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<H[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int A[]={7,3,9,10,4,2};
    int n=6;

    InsertionSort(A,n);
    Display(A,n);
    return 0;
}