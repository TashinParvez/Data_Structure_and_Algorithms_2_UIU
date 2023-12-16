
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int spanningTree(int N, vector<vector<int>> adj[])
    {
        int parent[N + 1];

        int key[N + 1];

        bool mstSet[N + 1];

        for (int i = 0; i <= N; i++)
            key[i] = INT_MAX, mstSet[i] = false;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        key[0] = 0;
        parent[0] = -1;
        pq.push({0, 0});

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            mstSet[u] = true;

            for (auto it : adj[u])
            {
                int v = it[0];
                int weight = it[1];
                if (mstSet[v] == false && weight < key[v])
                {
                    parent[v] = u;
                    key[v] = weight;
                    pq.push({key[v], v});
                }
            }
        }

        int mstWeight = 0;
        for (int i = 1; i <= N; i++)
        {
            if (key[i] != INT_MAX)
                mstWeight += key[i];
        }
        return mstWeight;
    }
};
/******************************************************************************/

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> key(V,INT_MAX);
        vector<bool> visited(V,false);
        vector<int> parent(V,-1);
        
        key[0]=0;
        parent[0]=-1;
        
        for(int i=0;i<V;i++){
            int mini=INT_MAX;
            int u;
            for(int j=0;j<V;j++){
                if(!visited[j] && mini>key[j]){
                    mini=key[j];
                    u=j;
                }
            }
            visited[u]=true;
            for(auto v:adj[u]){
                if(!visited[v[0]] && key[v[0]]>v[1]){
                    key[v[0]]=v[1];
                    parent[v[0]]=u;
                }
            }
        }
        int ans=0;       
        
        for(int i=1;i<V;i++){
            ans+=key[i];
        }
        return ans;
    }
};

/******************************************************************************/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends