#include <bits/stdc++.h>
using namespace std;

//const int N = 1e5 + 2;
map<string,bool> vis ;//bool vis[N];
map<string,vector<string>> adj; //vector<int> adj[N];
queue<string> q;


void setVisitedtoZero()
{
    for(auto pair:adj) //adj=N
    {
        vis[pair.first] = false; //string = pair.first, so false value is stored in vis(initialize)
    }
}

void DFS(string node)
{
    vis[node] = true;
    cout<<node<<" ";

    for (auto it:adj[node])
    {
        if(!vis[it])
        {
            DFS(it); // auto directly returns value so no *it req
        }
    }
}

void BFS()
{
    if(q.empty())
        return;

    string node = q.front();
    q.pop();
    cout<<node<<" ";

    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            vis[it] = true;
            q.push(it);
        }
    }

    BFS();
}

int main()
{

    int n,m;
    cout<<"Enter the number of routes[edges] and cities[vetices] of the graph:\n";
    cin>>n>>m;

    string x,y;
    cout<<"Enter starting and ending cities[vertices] of the edges:\n";
    
    for(int i=0; i<n; i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int choice;

    do
    {
        cout<<"\n----MENU----\n";
        cout<<"1. DFS\n2. BFS\n3. Exit\n";
        cout<<"Enter the choice: ";

        cin>>choice;
        string node;
        switch(choice)
        {
            case 1:
                    cout<<"Enter the city to start with:\n";
                    cin>>node;
                    cout<<"\nDFS:\n";
                    setVisitedtoZero();
                    DFS(node);
                    break;


            case 2: 
                    cout<<"Enter the city to start with:\n";
                    cin>>node;
                    q.push(node);
                    cout<<"\nBFS:\n";
                    setVisitedtoZero();
                    vis[node] = true;
                    BFS();
                    break;
 
        }

    } while(choice!=3);

    return 0;
}