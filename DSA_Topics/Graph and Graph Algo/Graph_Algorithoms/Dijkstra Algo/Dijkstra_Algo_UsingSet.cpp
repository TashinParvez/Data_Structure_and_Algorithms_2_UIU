
//        ****************  Author :  Tashin.Parvez  ****************
//        ************* United International University *************
//        ****************  Updated:    27/10/23     ****************

// BABAR: https://www.youtube.com/watch?v=dVUR3Rm6biE

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
#define null NULL
#define sp " " // space
#define setDec(x) fixed << setprecision(x)
#define len(s) s.length()
#define deb(n) cout << "Tashin   " << #n << " = " << n << endl; // debug code
#define debt cout << "Tashin   " << endl;                       // debug code

using namespace std;

vector<int> dijkstraAlgo_UsingSet(map<int, vector<pair<int, int>>> adj, int totalVertices, int totalEdges, int source)
{
    vector<int> distance(totalVertices); /// (Output Vector) store all distance from the source to particular node
    for (auto i : distance)
    {
        i = INT_MAX; /// can't reach
    }
    distance[source] = 0; /// source to source distance = 0

    set<pair<int, int>> st;
    // <distance  &  v-Node>

    st.insert({0, source});

    while (!st.empty())
    {
        auto top = *(st.begin());

        int dis = top.first; /// distance from source to u
        int u = top.second;  /// New Node  I will reach, So now I will go somewhere from this node

        st.erase(st.begin()); /// remove top cz this edge is picked

        for (auto i : adj[u])
        {
            int v = i.first;                  /// want to go next
            if (distance[v] > dis + i.second) /// distance[v] = ??
                                              /// dis + i.second = (distance of source to u + dis of u to v)
            {
                auto record = st.find({distance[v], v});
                if (record != st.end())
                {
                    st.erase(record);
                }

                /// distance update
                distance[v] = dis + i.second;

                /// push new record
                st.insert({distance[v], v}); /// From u --> v
            }
        }
    }

    return distance;
}

int32_t main()
{

    int totalVertices, totalEdges, source;
    cout << nl << "Enter total vertexs & total Edges : ";
    cin >> totalVertices >> totalEdges;

    map<int, vector<pair<int, int>>> adj; ///----> adjacency List
    //  u-vertex    < v-vertex  edge-weight >

    cout << "Enter (u  to v) edge & weight     as u, v , w" << nl; ///  (u  to v)  edge weight w
    for (int i = 0; i < totalEdges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w}); /// u --> v
        adj[v].push_back({u, w}); /// v --> u
    }

    cout << nl << "Enter source: "; /// taking starting pont
    cin >> source;

    vector<int> distance = dijkstraAlgo_UsingSet(adj, totalVertices, totalEdges, source);

    cout << "Press -1 to exit" << nl << nl;
    while (true)
    {
        cout << "Enter which nodes SSSP you want to know from source(u)= " << source << "  : ";
        int v;
        cin >> v;

        if (v == -1)
            break;
        cout << "Distance form (" << source << " to " << v << ") is " << distance[v] << nl << nl;
    }

    CRACKED;
}

/*
   4 5

   0 1 5
   0 2 8
   1 2 9
   1 3 2
   2 3 6

   0

*/

/*

6 8

0 1 10
0 2 1
2 3 7
2 1 2
1 3 3
3 5 3
3 4 2
4 5 2

0

*/