#include<iostream>
using namespace std;

void Display(int H[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<H[i]<<" ";
    }
    cout<<endl;
}

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
            
            if(H[p]<H[q])
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



void MergeSort(int H[],int n)
{
    int p;
    for(p=2;p<=n;p*=2)
    {
        int i;
        int last;
        for(i=0;i+p-1<=n;i+=p)
        {
            int mid=(2*i+p-1)/2;
            Merge(H,i,mid,i+p-1);
        }
    }
    if(p/2<n)
    {
        Merge(H,0,p/2-1,n);
    }
}

int main()
{
    int A[]={7,3,9,10,4,2};
    int n=6;

    MergeSort(A,n-1);
    Display(A,n);
    return 0;
}