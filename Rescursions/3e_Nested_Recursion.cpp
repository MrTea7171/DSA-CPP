/*
Nested Recursion- calling a function using the function itself as a parameter.
*/

#include<iostream>
using namespace std;

int x=0;
int fun(int a)
{
    x++;
    if(a>100)
    {
        return a-10;
    }
    return fun(fun(a+11));
}

int main()
{
    int a=95;
    cout<<fun(a)<<endl;
    cout<<x;
    return 0;
}