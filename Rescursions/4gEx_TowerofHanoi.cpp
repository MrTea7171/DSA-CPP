//Tower to Hanoi

#include<iostream>
using namespace std;

void toh(int n,string A,string B,string C)
{
    static int move=1;
    if(n>0)
    {
        toh(n-1,A,C,B);
        cout<<move++<<".Move From "<<A<<" to "<<C<<"."<<endl;
        toh(n-1,B,A,C);
    }
}

int main()
{   
    toh(2,"Box1","Box2","Box3");
    return 0;
}