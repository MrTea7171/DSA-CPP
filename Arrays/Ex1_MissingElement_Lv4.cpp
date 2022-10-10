//Multiple Missing Elements
//Unsorted and Using Hash
#include<iostream>
using namespace std;

int main()
{
    int arr[7]={3,6,1,5,8,9,2};
    int hash[9]={0,0,0,0,0,0,0,0,0};
    for(int i=0;i<7;i++)
    {
       hash[arr[i]]++;
    }
    for(int i=1;i<9;i++)
    {
        if(hash[i]==0)
        {
            cout<<"Missing ELements are: "<<i<<endl;
        }
    }
    return 0;
}