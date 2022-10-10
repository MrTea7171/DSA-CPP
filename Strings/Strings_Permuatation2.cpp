#include<iostream>
using namespace std;

void Permutation(string s)
{
    static int l=0;
    static int h=s.length()-1;
    if(l==h)
    {
        cout<<s<<endl;
    }
    else
    {
        for(int i=l;i<=h;i++)
        {
            swap(s[l],s[i]);
            l++;
            Permutation(s);
            l--;
            swap(s[l],s[i]);
        }
    }
}

int main()
{
    string s="ABC";
    Permutation(s);
    return 0;
}