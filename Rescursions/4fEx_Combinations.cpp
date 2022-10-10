//Combinations

#include<iostream>
using namespace std;

static int arr[20][20];
static int count1=0;
static int count2=0;

//Excessive Function
int excessive_combination(int n,int r)
{
    count1++;
    if(r==0 || n==r)
        return 1;
    return excessive_combination(n-1,r-1)+excessive_combination(n-1,r);
}

//Memoization Function
int memo_combination(int n,int r)
{
    count2++;
    if(r==0 || n==r)
        return 1;
    else
    {
        if(!arr[n-1][r-1])
        {
            arr[n-1][r-1]=memo_combination(n-1,r-1);
        }
        if(!arr[n-1][r])
        {
            arr[n-1][r]=memo_combination(n-1,r);
        }
        return arr[n-1][r-1]+arr[n-1][r];
    }
}

int main()
{   
    cout<< excessive_combination(4,2)<<endl;
    cout<<count1<<endl;
    cout<< memo_combination(4,2)<<endl;
    cout<<count2<<endl;
    return 0;
}