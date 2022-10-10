//Taylor Series (e^x)

#include<iostream>
using namespace std;

double taylor(int num,int extension)
{
    static int fact=1;
    static int power=1;
    if(extension==0)
        return 1;
    else
    {
        double r=taylor(num,extension-1);
        power=power*num;
        fact=fact*extension;
        return (static_cast<double>(power)/fact)+r;
    }
}

int main()
{
    int num=3;
    int extension=10;
    cout<<taylor(num,extension);
    return 0;
}