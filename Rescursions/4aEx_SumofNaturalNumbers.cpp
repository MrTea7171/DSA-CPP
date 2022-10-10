//Sum of natural numbers

#include<iostream>
using namespace std;

int sum(int a)
{
    if(a==0)
    {
        return 0;
    }
    return sum(a-1)+a;
}

int main()
{
    int a=10;
    cout<<sum(a);
    return 0;
}