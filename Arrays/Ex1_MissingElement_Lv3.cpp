//Multiple Missing Elements
#include<iostream>
using namespace std;

int main()
{
    int arr[7]={6,7,8,10,11,15,18};
    int diff=arr[0];
    for(int i=0;i<7;i++)
    {
       if(arr[i]-i!=diff)
       {
            while(diff<(arr[i]-i))
            {
                cout<<"Element Missing is: "<<i+diff<<endl;
                diff++;
            }
       } 
    }
    return 0;
}