#include<iostream>
using namespace std;

int main()
{
    int arr[10]={3,6,8,8,10,12,15,15,15,20};
    int i=0;
    while(i<9)
    {
        if(arr[i]==arr[i+1])
        {
            int j=i+1;
            while(arr[j]==arr[i])
            {
                j++;
            }
            cout<<arr[i]<<" is repeadted "<<j-i<<" times."<<endl;
            i=j-1;
        }
        i++;
    }
    return 0;
}