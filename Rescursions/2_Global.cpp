#include<iostream>
using namespace std;
int x=0;

int fun(int a)
{
    if(a>0)
    {
        x++;
        return fun(a-1)+x;
    }
    return 0;
}

int main()
{
    int a=5;
    cout<<fun(5);
    return 0;
}