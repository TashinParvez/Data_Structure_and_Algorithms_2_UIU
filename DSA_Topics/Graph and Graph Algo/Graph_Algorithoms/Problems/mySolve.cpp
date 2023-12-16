//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    struct EdgeInfo
    {
        int u;
        int v;
        int weight;
    };

    static bool compare(EdgeInfo a, EdgeInfo b)
    {
        return a.weight < b.weight;
    }

    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> visited(V, 0);
        vector<EdgeInfo> edges;

        int i = 0;
        while (i < V)
        {
            int cost = INT_MAX;
            EdgeInfo edg;

            for (auto j : adj[i])
            {
                if (cost > j[1])
                {
                    cost = j[1];

                    edg.u = i;
                    edg.v = j[0];
                    edg.weight = j[1];
                }
            }

            edges.push_back(edg);
            i++;
        }

        sort(edges.begin(), edges.end(), compare); /// sort based on their weight
        int MSTcost = 0;
        for (auto i : edges)
        {
            if (visited[i.u] == 0 || visited[i.v] == 0)
            {

                // cout << i.u << " ---> " << i.v << endl;

                MSTcost += i.weight;
                visited[i.u] = 1;
                visited[i.v] = 1;
            }
        }

        return MSTcost;
    }
};

//{ Driver Code Starts.

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