#include<iostream>
using namespace std;

void Merge(int H[],int low,int mid,int high)
{
    if(low<high)
    {
        int p=low;
        int q=mid+1;
        int ans[high-low];
        int k=0;

        while(p<=mid && q<=high)
        {
            if(H[p]<=H[q])
            {
                ans[k++]=H[p++];
            }
            else
            {
                ans[k++]=H[q++];
            }
        }

        while(p<=mid)
        {
            ans[k++]=H[p++];
        }

        while(q<=high)
        {
            ans[k++]=H[q++];
        }

        for(int i=0;i<k;i++)
        {
            H[low+i]=ans[i];
        }
    }
}

void MergeSort(int H[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        MergeSort(H,low,mid);
        MergeSort(H,mid+1,high);
        Merge(H,low,mid,high);
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

    MergeSort(A,0,n-1);
    Display(A,n);
    return 0;
}