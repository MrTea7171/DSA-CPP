#include<iostream>
using namespace std;

int main()
{
    int arr[10]={6,3,8,10,16,7,5,2,9,14};
    int hash[15];
    for(int &x:hash)
    {
        x=0;
    }
    for(int i=0;i<10;i++)
    {
        if(arr[i]<10 && hash[10-arr[i]]==1)
        {
            cout<<"{"<<arr[i]<<","<<10-arr[i]<<"}"<<endl;
        }
        hash[arr[i]]=1;
    }
    return 0;
}