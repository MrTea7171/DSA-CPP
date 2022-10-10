//power of natural numbers

#include<iostream>
using namespace std;

int power(int num,int raise)
{
    if(raise==0)
        return 1;
    else
        return power(num,raise-1)*num;
}

int main()
{
    int num=2;
    int raise=5;
    cout<<power(num,raise);
    return 0;
}