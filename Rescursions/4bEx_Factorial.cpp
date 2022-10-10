//Factorial of natural numbers

#include<iostream>
using namespace std;

int fact(int a)
{
    if(a==0)
        return 1;
    else
        return fact(a-1)*a;
}

int main()
{
    int a=0;
    cout<<fact(a);
    return 0;
}