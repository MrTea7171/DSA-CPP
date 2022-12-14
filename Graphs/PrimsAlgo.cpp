#include<iostream>
#define I INT32_MAX

using namespace std;

int cost[][8]={
    {I,I,I,I,I,I,I,I},
    {I,I,25,I,I,I,5,I},
    {I,25,I,12,I,I,I,10},
    {I,I,12,I,8,I,I,I},
    {I,I,I,8,I,16,I,14},
    {I,I,I,I,16,I,20,18},
    {I,5,I,I,I,20,I,I},
    {I,I,10,I,14,18,I,I}
};

int near[8]={I,I,I,I,I,I,I,I};
int t[7];

int main()
{
    int i,j,v1,v2;
    int n=8;
    int k=0;
    int min=I;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(min>cost[i][j])
            {
                min=cost[i][j];
                v1=i;
                v2=j;
            }
        }
    }

    t[k++]=v1;
    t[k++]=v2;

    for(int i=1;i<n;i++)
    {
        if(cost[i][v1]<cost[i][v2])
        {
            near[i]=v1;
        }
        else
        {
            near[i]=v2;
        }
    }

    near[v1]=0;
    near[v2]=0;

    for(int i=1;i<n-1;i++)
    {
        int nextMin=I;
        int nextV;
        for(int j=1;j<n;j++)
        {
            if(near[j]!=0 && cost[j][near[j]]<nextMin)
            {
                nextMin=cost[j][near[j]];
                nextV=j;
            }
            
        }

        //cout<<nextMin<<" "<<nextV<<" "<<near[nextV]<<endl;

        t[k++]=nextV;
        near[nextV]=0;

        for(int j=1;j<n;j++)
        {
            if(near[j]!=0 && cost[j][nextV]<cost[j][near[j]])
            {
                near[j]=nextV;
            }
        }

    }

    for(int i=0;i<n-1;i++)
    {
        cout<<t[i]<<" ";
    }

    return 0;
}