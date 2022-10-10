#include<iostream>
using namespace std;

int main()
{
    int arr[10]={8,3,6,4,6,5,6,8,2,7};
    for(int i=0;i<10;i++)
    {
        int count=1;
        if(arr[i]!=-1)
        {
            for(int j=i+1;j<10;j++)
            {
                if(arr[i]==arr[j])
                {
                    arr[j]=-1;
                    count++;
                }
            }

            if(count>1)
            {
                cout<<arr[i]<<" is repeated "<<count<<" times."<<endl;
            }
        }
    }
    return 0;
}