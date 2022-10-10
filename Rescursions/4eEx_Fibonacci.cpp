//Fibonaci Series
//Excessive Recursion & Memoization

#include<iostream>
using namespace std;

static int arr[20];

//Excessive Function
int excessive_fib(int n)
{
    if(n<=1)
        return n;
    return excessive_fib(n-2)+excessive_fib(n-1);
}


//Memoization Function
int memo_fib(int n)
{
    if(n<=1)
        return n;
    else
    {
        if(arr[n-2]==-1)
        {
            arr[n-2]=excessive_fib(n-2);
        }
        if(arr[n-1]==-1)
        {
            arr[n-1]=excessive_fib(n-1);
        }
        return arr[n-1]+arr[n-2];
    }
}

int main()
{
    for(int &x:arr)
    {
        x=-1;
    }
    cout<<excessive_fib(1)<<endl;
    cout<<memo_fib(5)<<endl;
    return 0;
}