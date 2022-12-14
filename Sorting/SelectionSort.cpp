#include<iostream>
using namespace std;

void SelectionSort(int H[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min_position=i;
        for(int j=i;j<n;j++)
        {
            if(H[min_position]>H[j])
                min_position=j;
        }
        swap(H[i],H[min_position]);
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

    SelectionSort(A,n);
    Display(A,n);
    return 0;
}