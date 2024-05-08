#include<bits/stdc++.h>
using namespace std;
class DSU
{
    public:
    vector<int>size,parent;
    DSU(int n) //constructor
    {
        size.resize(n+1,1); // intially sare nodes ka size "1" hota hai [SIZE intialize]
        parent.resize(n+1);  
        for(int i=0;i<=n;i++) // we traverse n only obv- no of nodes
        {
            parent[i]=i; //[PARENT intitialize]
        }
    }
    //Path Compression
    int findUPar(int node)
    {
        if(node==parent[node])
        return node;
        return parent[node]=findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v)
        return;

        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }

};
int main()
{
    int v,e;
    cout<<"Enter number of vertices"<<endl;
    cout<<"Enter number of edges"<<endl;
    cin>>v>>e;
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0;i<e;i++)
    {
        cout<<"Edge"<<endl;
        int st,en,wt;
        cin>>st>>en>>wt;
        edges.push_back({wt,{st,en}});
    }
    sort(edges.begin(),edges.end()); // sort edges according to weight
    vector<pair<int,pair<int,int>>>ans;
    int minwt=0;
    DSU d(v); //object d of class DSU[disjoint set union]
    for(auto e:edges)
    {
        int n1=e.second.first;
        int n2=e.second.second;
        int wt=e.first;
        int par_n1=d.findUPar(n1);
        int par_n2=d.findUPar(n2);
        if(par_n1!=par_n2)
        {
            ans.push_back({wt,{n1,n2}});
            d.unionBySize(n1,n2);
            minwt+=wt;
        }
    }
    cout<<"minwt="<<minwt<<endl;
    for(auto e:ans)
    {
        cout<<e.first<<"->"<<e.second.first<<" "<<e.second.second<<endl;
    }
    
    return 0;
}