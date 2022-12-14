#include<bits/stdc++.h>
using namespace std;

void DFS(int G[][7],int start,int n)
{
    int visited[7]={0};

    int i=start;
    int j;
    cout<<i<<" ";
    visited[i]=1;

    stack<int> s;
    s.push(i);
    while(!s.empty())
    {
        i=s.top();
        s.pop();
        for(int j=0;j<n;j++)
        {
            if(G[i][j]==1 && visited[j]==0)
            {
                visited[j]=1;
                cout<<j<<" ";
                s.push(i);
                s.push(j);
                break;
            }
        }
    }
}

int main()
{
    int G[7][7]={
        {0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0},
        {0,1,0,0,1,0,0},
        {0,1,0,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    DFS(G,1,7);
    cout<<endl;
    DFS(G,3,7);
    cout<<endl;
    DFS(G,6,7);
    return 0;
}