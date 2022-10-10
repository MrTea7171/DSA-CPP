/*
Indirect Recursion- Cyclic function call.
*/

#include<iostream>
using namespace std;
void funA(int);
void funB(int);

void funA(int a)
{
    if(a>0)
    {
        cout<<a<<endl;
        funB(a-1);
    }
}

void funB(int a)
{
    if(a>1)
    {
        cout<<a<<endl;
        funA(a/2);
    }
}

int main()
{
    int a=20;
    funA(a);
    return 0;
}