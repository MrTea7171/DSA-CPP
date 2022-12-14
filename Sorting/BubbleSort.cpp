#include<iostream>
using namespace std;

void BubbleSort(int H[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(H[i]>H[j])
                swap(H[i],H[j]);
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

    BubbleSort(A,n);
    Display(A,n);
    return 0;
}