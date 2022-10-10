//Taylor Series using Horner's rule
#include<iostream>
using namespace std;

double e(int num,int extension)
{
    static double sum=1;
    if(extension==0)
        return sum;
    sum=1+(static_cast<double>(num)/extension)*sum;
    return e(num,extension-1);
}

int main()
{
    int num=3;
    int extension=10;
    cout<<e(num,extension);
    return 0;
}