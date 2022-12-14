#include<iostream>
using namespace std;

void QuickSort(int H[],int low,int high)
{
    if(low<high)
    {
        int pivot=H[low];
        int i=low;
        int j=high;
        while(i<j)
        {
            while(H[i]<=pivot && i<high)
            {
                i++;
            }
            while(H[j]>pivot && j>=low)
            {
                j--;
            }
            if(i<j)
                swap(H[i],H[j]);
            
        }
        swap(H[low],H[j]); 
        QuickSort(H,low,j);
        QuickSort(H,j+1,high);
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

    QuickSort(A,0,n-1);
    Display(A,n);
    return 0;
}