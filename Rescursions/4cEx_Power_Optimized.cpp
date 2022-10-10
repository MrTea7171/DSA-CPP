//power of natural numbers --optimised

#include<iostream>
using namespace std;

int power(int num,int raise)
{
    if(raise==0)
        return 1;
    else if(raise%2==0)
        return power(num*num,(raise)/2);
    else
        return num*power(num*num,(raise-1)/2);
}

int main()
{
    int num=3;
    int raise=5;
    cout<<power(num,raise);
    return 0;
}