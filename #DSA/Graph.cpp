#include<bits/stdc++.h>
using namespace std;
// ******************************************************************
##cycle detection(dfs) : ug 

bool chkdfs(int node,int par,vector<int>& vis,vector<int> adj[])
{
    vis[node] = 1;
    for(auto child:adj[node])
    {
        if(!vis[child])
        {
            if(chkdfs(child,node,vis,adj)) return true;
        }
        else if(child != par) return true;
    }
    return false;
}

bool iscycle(int v,vector<int> adj[])
{
    vector<int> vis(v+1,0);
    // for multiple connected components...
    for(int i=1;i<=v;++i)
    {
        if(!vis[i])
        {
            if(chkdfs(i,-1,vis,adj)) return true;
        }
    }
    return false;
}

tc : o(v+e) 
sc : o(v+e) + o(v) + o(v)
v is time taken to travel v nodes 
and e is for traveling through adjacent nodes.

// ******************************************************************
## cycle detection(dfs) : Dg 

bool chkdfs(int node,vector<int>& vis,vector<int>& bfsvis,vector<int> adj[])
{
    vis[node] = 1;
    bfsvis[node] = 1;
    
    for(auto child:adj[node])
    {
        if(!vis[child])
        {
            if(chkdfs(child,vis,dfsvis,adj)) return true;
        }
        else if(bfsvis[child]) return true;
    }
    bfsvis[node] = 0;
    return false;
}

bool iscycle(int v,vector<int> adj[])
{
    vector<int> vis(v+1,0);
    vector<int> bfdvis(v+1,0);

    for(int i=1;i<=v;++i)
    {
        if(!vis[i]) 
        {
            if(chkdfs(i,vis,bfsvis,adj)) return true;
        }
    }
    return false;
}

tc = as it is dfs so o(v+e).
sc = o(v+e) + o(v) + {o(v) + o(v)} vis and bfsvis ...

// ******************************************************************
## topo sort(dfs) 

// only for DAG
// there are multiple such sorted order..    
// stack , visited array 

void dfs(int node,stack<int>& st,vector<int>& vis,vector<int> adj[])
{
    vis[node] = 1;
    for(auto child:adj[node])
    {
        if(!vis[child])
        {
            dfs(child,st,vis,adj);
        }
    }
    // As soon as the dfs for node is over...push it in stack
    st.push(node);
}

vector<int> topo(int v,vector<int> adj[])
{
    stack<int> st;
    vector<int> vis(v+1,0);
    vector<int> ans;

    for(int i=1;i<=v;++i)
    {
        if(!vis[i])
        {
            dfs(i,st,vis,adj);
        }
    }

    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

tc = same as dfs algo.
sc = o(v+e) and o(v) for recursion stack , stack , vis array

// ******************************************************************
## topo sort(bfs) 

// indegree of node is the incoming edges to that node 
// as soon as the indegree of node ==0 put it in the queue.
// once node is taken out of queue push that node in ans vector..

*** indegree array ,, queue ***

vector<int> topo(int v,vector<int> adj[]) 
{
    vector<int> indegree(v,0);
    queue<int> q;
    for(int i=0;i<v;++i) 
    {
        for(auto child:adj[i])
        {
// indegree of node is the incoming edges to that node 
            indegree[child]++;
        }
    }

    for(int i=0;i<v;++i)
    {
// as soon as the indegree of node ==0 put it in the queue.
        if(indegree[i]==0) q.push(i);
    }

    vector<int> ans;
    // bfs algo 
    while(!q.empty()) 
    {
        int node =  q.front();
        q.pop();
// once node is taken out of queue push that node in ans vector..
        ans.push_back(node); 

        for(auto child:adj[node])
        {
            --indegree[child];
            if(indegree[child]==0) q.push(child);
        }
    }
    return ans;
}

tc = same as of bfs.
sc = adj list + queue + indegree array ...

//*****************************************************************
## cycle detection(bfs) : dg  ##

logic : use of topo sort (bfs)...
that is if topo sort exists then it is acyclic dg.
that is no cycle ...

bool<int> topo(int v,vector<int> adj[])
{
    vector<int> indegree(v,0);
    queue<int> q;
    for(int i=0;i<v;++i)
    {
        for(auto child:adj[i])
        {
// indegree of node is the incoming edges to that node 
            indegree[child]++;
        }
    }

    for(int i=0;i<v;++i)
    {
// as soon as the indegree of node ==0 put it in the queue.
        if(indegree[i]==0) q.push(i);
    }

    vector<int> ans;
    int cnt = 0;

    // bfs algo 
    while(!q.empty()) 
    {
        int node =  q.front();
        q.pop();
// once node is taken out of queue push that node in ans vector..
        ans.push_back(node); 
        ++cnt;

        for(auto child:adj[node])
        {
            --indegree[child];
            if(indegree[child]==0) q.push(child);
        }
    }
// if cnt == nodes then topo exists 
    if(cnt == v) return false;
    else return true;
}


// ******************************************************************

## shortest path in ug(unit wt): ##

bfs : queue

vector<int> bfs(int src,int v,vector<int> adj[])
{
    vector<int> dist(v,INT_MAX);
    queue<int> q;

    q.push(src);
    dist[src] = 0;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto child:adj[node])
        {
            if(dist[node] + 1 < dist[child]) 
            {
                dist[child] = dist[node] + 1;
                q.push(child);
            }
        }
    }
    return dist;
}

// ******************************************************************

dijkstra algo is not valid for negative wt.
consider a edge with negative wt. then it will go 
on infinetely....



DIJKSTRA ALGO (SERIES)
##1. Priority queue....

vector<int> dijk(int v,vector<vector<int>> adj[],int src)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(v,INT_MAX);

    dist[src] = 0;
    pq.push({0,src});

    while(!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto child:adj[node])
        {
            int edgewt = child[1];
            int adjnode = child[0];

            if(dist[node] + edgewt < dist[adjnode])
            {
                dist[adjnode] = dist[node] + edgewt;
                pq.push({dist[adjnode],adjnode});
            }
        }
    }
    return dist;
}

// ******************************************************************

##2. set 

vector<int> dijk(int v,vector<vector<int>> adj[],int src)
{
    vector<int> dist(v,1e9);
    set<pair<int,int>> st;

    st.insert({0,src});
    dist[src] = 0;

    while(!st.empty())
    {
        auto it = *(st.begin());
        int dis = it.first;
        int node = it.second;
        st.erase(st.begin());

        for(auto child:adj[node])
        {
            int edgewt = child[1];
            int adjnode = child[0];
            if(dis + edgewt < dist[adjnode])
            {
                // if node is already visited....
                if(dist[adjnode] != 1e9)
                st.erase({dist[adjnode],adjnode});

                dist[adjnode] = dis + edgewt;
                st.insert({dist[adjnode],adjnode});
            } 
        }
    }
    return dist;
}

// ******************************************************************

if we use queue in place of priority queue...
then we have to traverse thru all the paths , not the 
minimal paths ....
hence it will be like a brute force approach....


// ******************************************************************


TIME COMPLEXITY : E (log v)

// ******************************************************************
// ******************************************************************
// ******************************************************************









