/*
Tree Recursion- Multiple Recursive Call inside function.
*/

#include<iostream>
using namespace std;

int x=0;
void fun(int a)
{
    x++;
    if(a>0)
    {
        cout<<a<<endl;
        fun(a-1);
        fun(a-1);
    }
}

int main()
{
    int a=5;
    fun(a);
    cout<<x;
    return 0;
}