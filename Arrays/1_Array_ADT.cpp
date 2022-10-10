#include<iostream>
using namespace std;

struct Array
{
    int *arr;
    int size;
    int lenght=0;
};

int main()
{
    struct Array A1;
    int i,n;
    cout<<"Enter Array Size:"<<endl;
    cin>>A1.size;
    A1.arr=new int[A1.size];
    cout<<"Enter number of elements to be added"<<endl;
    cin>>n;
    cout<<"Enter elements to be added"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>A1.arr[i];
    }
    A1.lenght=n;
    cout<<"Elements in array are: "<<endl;
    for(i=0;i<A1.lenght;i++)
    {
        cout<<A1.arr[i]<<" ";
    }
    return 0;
}