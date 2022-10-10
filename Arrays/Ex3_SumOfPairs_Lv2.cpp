#include<iostream>
using namespace std;

int main()
{
    int arr[10]={1,3,4,5,6,8,9,10,12,14};
    int i=0;
    int j=9;
    while(i<j)
    {
        if(arr[i]+arr[j]==10)
        {
            cout<<"{"<<arr[i]<<","<<arr[j]<<"}"<<endl;
            i++;
            j--;
        }
        else if(arr[i]+arr[j]>10)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return 0;
}