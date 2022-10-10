#include<iostream>
using namespace std;

void Permutation(string s)
{
    static int arr[10]={0};
    static char res[10];
    static int k=0;

    if(s[k]=='\0')
    {
        res[k]='\0';
        cout<<res<<endl;
    }
    else
    {
        for(int i=0;s[i]!='\0';i++)
        {
            if(arr[i]==0)
            {
                res[k]=s[i];
                arr[i]=1;
                k++;
                Permutation(s);
                arr[i]=0;
                k--;
            }
        }
    }
}

int main()
{
    string s="ABC";
    Permutation(s);
    return 0;
}