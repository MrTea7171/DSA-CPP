#include<iostream>
using namespace std;

int main()
{
    int arr[10]={3,6,8,8,10,12,15,15,15,20};
    int i=0;
    int lastduplicate=0;
    while(i<9)
    {
        if(arr[i]==arr[i+1] && lastduplicate!=arr[i])
        {
            cout<<arr[i]<<endl;
            lastduplicate=arr[i];
        }
        i++;
    }
    return 0;
}