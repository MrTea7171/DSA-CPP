/*
Tail Recursion- Function call is the last line in the recursion with no additional work.
*/

#include<iostream>
using namespace std;

void fun(int a)
{
    if(a>0)
    {
        cout<<a<<endl;
        fun(a-1);
    }
}

int main()
{
    int a=5;
    fun(a);
    return 0;
}