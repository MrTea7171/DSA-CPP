/*
Head Recursion- Function call is the first line in the recursion with no additional work.
*/

#include<iostream>
using namespace std;

void fun(int a)
{
    if(a>0)
    {
        fun(a-1);
        cout<<a<<endl;
    }
}

int main()
{
    int a=5;
    fun(a);
    return 0;
}