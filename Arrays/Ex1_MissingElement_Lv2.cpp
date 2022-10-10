#include<iostream>
using namespace std;

int main()
{
    int arr[7]={6,7,8,10,11,12,13};
    int diff=arr[0];
    for(int i=0;i<7;i++)
    {
       if(arr[i]-i!=diff)
       {
            cout<<"Element Missing is: "<<i+diff;
            break;
       } 
    }
    return 0;
}