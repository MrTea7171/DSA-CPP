//Check Duplicate using Bits
#include<iostream>
using namespace std;

int main()
{
    string name="chaitanya";
    long int h,x;
    h=x=0;

    for(char c:name)
    {
        x=1;
        x<<=(c-97);
        if(x&h>0)
        {
            cout<<"Duplicate Found: "<<c<<endl;
        }
        else
        {
            h=x|h;
        }
    }
    return 0;
}