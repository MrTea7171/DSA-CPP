#include<bits/stdc++.h>
using namespace std;

void BFS(int G[][7],int start,int n)
{
    int i=start;
    int j;
    int visited[n]={0};
    queue<int> q;
    
    cout<<i<<" ";
    visited[i]=1;
    q.push(i);

    while(!q.empty())
    {
        i=q.front();
        q.pop();
        for(int j=0;j<n;j++)
        {
            if(G[i][j]==1 && visited[j]==0)
            {
                cout<<j<<" ";
                visited[j]=1;
                q.push(j);
            }
        }
    }

    cout<<endl;
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
    BFS(G,1,7);
    BFS(G,3,7);
    BFS(G,6,7);
    return 0;
}