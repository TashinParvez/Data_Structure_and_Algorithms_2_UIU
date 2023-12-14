
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
    return a.weight <= b.weight;
}

/** Disjoint Set Parts **/

int parent[1000];
int rankOfThistree[1000];

void makeSet(int i)
{
    parent[i] = i;
    rankOfThistree[i] = 0;
}

int findparent(int a) /// finding grand parent
{
    if (parent[a] == a)
        return a;
    else
    {
        /// This is the Heuristic ( Pa}th Compression ) of Find Parent

        int friend_ = findparent(parent[a]);
        parent[a] = friend_; /// this is doing to minimize the complexity for the same case in future
        return parent[a];
    }
}

bool unionSet(int a, int b)
{
    int parentof_A = findparent(a);
    int parentof_B = findparent(b);

    if (parentof_A == parentof_B)
    {
        return true;
    }
    else
    {
        /// Union heuristic (Union Rank)

        if (rankOfThistree[parentof_A] == rankOfThistree[parentof_B])
        {
            parent[parentof_A] = parentof_B;
            rankOfThistree[parentof_B]++;
        }
        else if (rankOfThistree[parentof_A] > rankOfThistree[parentof_B])
        {
            parent[parentof_B] = parentof_A;
        }
        else if (rankOfThistree[parentof_A] < rankOfThistree[parentof_B])
        {
            parent[parentof_A] = parentof_B;
        }

        return false;
    }
}

/** END **/

int kruskalMST(vector<EdgeInfo> edges, int vertices)
{
    sort(edges.begin(), edges.end(), compare);

    for (int i = 0; i < vertices; i++)
    {
        makeSet(i);
    }

    int mstCost = 0;

    cout << nl << "Taken Edges : " << nl;
    for (EdgeInfo edge : edges)
    {
        /// if their parent are not same then i have to take this edge
        bool sameParent = unionSet(edge.u, edge.v); /// Checking parent same or not
        /// parent same means i cant take them

        if (sameParent == false)
        {
            cout << edge.u << " --> " << edge.v << nl;

            mstCost += edge.weight;
        }
    }

    return mstCost;
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

    int mstCost = kruskalMST(edges, numOfVertices);

    cout << nl << "MSTCost " << mstCost << nl << nl;

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
