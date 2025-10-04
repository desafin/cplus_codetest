#include<bits/stdc++.h>
using namespace std;

int N,M,V;
vector<int> adj[1001];
bool visited[1001];

void dfs(int u)
{
    visited[u]=true;
    cout<< u << " ";
    for (int v:adj[u])
    {
        if(!visited[v])
        {
            dfs(v);
        }
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start]=true;
    
    while(!q.empty())
    {
        int u =q.front();
        q.pop();
        cout<< u<<" ";
        
        for (int v:adj[u])
        {
            if(!visited[v])
            {
                q.push(v);
                visited[v]=true;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>N>>M>>V;
    
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    
    fill(visited,visited +1001,false);
    dfs(V);
    cout<<"\n";
    
    fill(visited,visited+1001,false);
    bfs(V);
    cout<<"\n";
    
    return 0;
}