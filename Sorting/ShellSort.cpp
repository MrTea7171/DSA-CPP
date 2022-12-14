#include<bits/stdc++.h>
using namespace std;


void Display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void shellSort(int A[],int n)
{
    int gap,i,j;
    for(gap=n/2;gap>1;gap/=2)
    {
        for(i=gap;i<n;i++)
        {
            int temp=A[i];
            j=i-gap;
            while(j>=0 && A[j]>temp)
            {
                A[j+gap]=A[j];
                j=j-gap;
            }
            A[j+gap]=temp;
        }
    }
}

int main()
{
    int arr[]={9,5,16,8,13,6,12,10,4,2,3};
    shellSort(arr,11);
    Display(arr,11);
    return 0;
}