
//        ****************  Author :  Tashin.Parvez  ****************
//        ************* United International University *************
//        ****************  Updated:    27/10/23     ****************

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

struct EdgeInfo
{
    int u;
    int v;
    int weight;
};
bool compare(EdgeInfo a, EdgeInfo b)
{
    return a.weight < b.weight;
}

int32_t main()
{
    int numOfVertices, numofEdge;
    cin >> numOfVertices >> numofEdge; /// input

    vector<EdgeInfo> edges;

    for (int i = 0; i < numofEdge; i++) /// taking u v and w
    {
        EdgeInfo edge;
        cin >> edge.u >> edge.v >> edge.weight;
        edges.push_back(edge);
    }

    sort(edges.begin(), edges.end(), compare); /// sort based on their weight

    /// print to check sort func
    // for (auto i : edges)
    // {
    //     cout << i.weight << nl;
    // }

    cout << nl << "Edges:  " << nl;
    vector<int> visited(numOfVertices, 0);

    int cnt = 0;
    int i = 0;   /// to iterate edges
    int cost = 1;  /// cost 

    while (cnt < numOfVertices)
    {
        if (visited[edges[i].u] == 0 || visited[edges[i].v] == 0)
        {
            cout << edges[i].u << "--" << edges[i].v << nl;
            cost *= edges[i].weight;

            if (visited[edges[i].u] == 0)
            {
                visited[edges[i].u] = 1;
                cnt++;
            }

            if (visited[edges[i].v] == 0)
            {
                visited[edges[i].v] = 1;
                cnt++;
            }
        }
        
        i++;
    }

    cout << "Minimum product: " << cost << nl << nl;

    CRACKED;
}

/*

5 7
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9


*/
