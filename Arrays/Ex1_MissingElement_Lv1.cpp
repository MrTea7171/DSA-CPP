#include<iostream>
using namespace std;

int main()
{
    int arr[7]={1,2,3,4,6,7,8};
    int sum=0;
    int s;
    for(int i=0;i<7;i++)
    {
        sum+=arr[i];
    }
    s=(8*9)/2;
    cout<<"Missing Number is: "<<s-sum;
    return 0;
}