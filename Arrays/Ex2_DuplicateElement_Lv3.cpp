#include<iostream>
using namespace std;

int main()
{
    int arr[10]={3,6,8,8,10,12,15,15,15,20};
    int hash[21];
    int i=0;
    for(int &x:hash)
    {
        x=0;
    }
    while(i<9)
    {
        hash[arr[i++]]++;
    }
    for(i=0;i<21;i++)
    {
        if(hash[i]>1)
        {
            cout<<i<<" is repeadted "<<hash[i]<<" times."<<endl;
        }
    }
    return 0;
}