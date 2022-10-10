#include<iostream>
using namespace std;

int main()
{
    int arr[10]={8,3,6,4,6,5,6,8,2,7};
    int hash[9];
    int i=0;
    for(int &x:hash)
    {
        x=0;
    }
    while(i<9)
    {
        hash[arr[i++]]++;
    }
    for(i=0;i<9;i++)
    {
        if(hash[i]>1)
        {
            cout<<i<<" is repeadted "<<hash[i]<<" times."<<endl;
        }
    }
    return 0;
}