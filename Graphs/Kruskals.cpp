#include<bits/stdc++.h>
#define I INT32_MAX
using namespace std;

int edges[3][9]={
    {1,1,2,2,3,4,4,5,5},
    {2,6,3,7,4,5,7,6,7},
    {25,5,12,10,8,16,14,20,18}
};

int MySet[8]={-1,-1,-1,-1,-1,-1,-1,-1};
int included[9]={0};
int t[2][6];

void MyUnion(int u,int v)
{
    if(MySet[u]<MySet[v])
    {
        MySet[u]=MySet[u]+MySet[v];
        MySet[v]=u;
    }
    else
    {
        MySet[v]=MySet[v]+MySet[u];
        MySet[u]=v;
    }
}

int MyFind(int u)
{
    int x=u,v=0;
    while(MySet[x]>0)
    {
        x=MySet[x];
    }

    while(u!=x)
    {
        v=MySet[u];
        MySet[u]=x;
        u=v;
    }

    return x;
}

int main()
{
    int i,j,k,u,v,min=I,n=7,e=9;
    i=0;
    while(i<n-1)
    {
        min=I;
        for(j=0;j<e;j++)
        {
            if(included[j]==0 && edges[2][j]<min)
            {
                min=edges[2][j];
                u=edges[0][j];
                v=edges[1][j];
                k=j;
            }

        }

        if(MyFind(u)!=MyFind(v))
        {
            t[0][i]=u;
            t[1][i]=v;
            MyUnion(MyFind(u),MyFind(v));
            i++;
        }

        included[k]=1;

    }

    for(i=0;i<n-1;i++)
    {
        cout<<"("<<t[0][i]<<" , "<<t[1][i]<<")"<<endl;
    }
}