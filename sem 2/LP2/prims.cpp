#include<bits/stdc++.h>
using namespace std;
int prims(vector<pair<int,int>>adj[],int n,int st,vector<pair<pair<int,int>,int>>&ans)
{
    priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, greater<pair<pair<int,int>,int>>> pq;
    pq.push({{0,st},-1});
    vector<int>vis(n,0);
    int minwt=0;
    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        int wt=it.first.first;
        int node=it.first.second;
        int parent=it.second;
        if(parent!=-1)
        {
            if(vis[node]==1)
            {
                continue;
            }
            vis[node]=1;  // visited array mai vo node ko 1 kar dete
            minwt+=wt;
            ans.push_back({{node, parent}, wt}); // and vo node [and its components] ko final ans mai push
        }
        else
        {
            vis[node]=1;
        }
        
        for(auto e:adj[node])
        {
            if(!vis[e.first])
            {
                pq.push({{e.second,e.first},node});
                
            }
        }

    }
    for(auto e:ans)
    {
        cout<<e.first.first<<","<<e.first.second<<" "<<e.second<<endl;
    }
    return minwt;
}
int main()
{
    int n,e;
    cout<<"Enter number of vertices"<<endl;
    cin>>n;
    cout<<"Enter number of edges"<<endl;
    cin>>e;
    vector<pair<int,int>>adj[n];
    for(int i=0;i<e;i++)
    {
        cout<<"Enter start node end node and weight"<<endl;
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    vector<pair<pair<int,int>,int>>ans;
    cout<<"Enter starting node"<<endl;
    int st;
    cin>>st;
    int minwt=prims(adj,n,st,ans);
    
    cout<<minwt<<endl;
    return 0;
}