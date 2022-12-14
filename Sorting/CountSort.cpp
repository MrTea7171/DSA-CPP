#include<iostream>
using namespace std;

void countSort(int H[],int n)
{
    int max;
    for(int i=0;i<n;i++)
    {
        max=H[i];
        if(max<H[i])
            max=H[i];
    }
    
    int countArr[max+1];

    for(int i=0;i<=max;i++)
    {
        countArr[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        countArr[H[i]]++;
    }

    int k=0;
    for(int i=0;i<=max;)
    {
        if(countArr[i]>0)
        {
            H[k++]=i;
            countArr[i]--;
        }
        else
        {
            i++;
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

    countSort(A,n);
    Display(A,n);
    return 0;
}