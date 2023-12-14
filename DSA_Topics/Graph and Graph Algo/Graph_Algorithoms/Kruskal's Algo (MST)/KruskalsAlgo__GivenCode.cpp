#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int u, v, w;
};

/** Disjoint Set Union - Start **/

int parent[107];
int rank_[107];

void makeSet(int x)
{
    parent[x] = x;
    rank_[x] = 0;
}

int findSet(int x)
{
    if (parent[x] == x)
        return x;
    else
    {
        int friend_ = findSet(parent[x]);
        parent[x] = friend_;
        return friend_;
    }
}

bool Union(int u, int v)
{
    int Ru = findSet(u);
    int Rv = findSet(v);

    if (Ru == Rv)
        return false;
    else
    {
        if (rank_[Ru] > rank_[Rv])
        {
            parent[Rv] = Ru;
        }
        else if (rank_[Rv] > rank_[Ru])
        {
            parent[Ru] = Rv;
        }
        else if (rank_[Ru] == rank_[Rv])
        {
            parent[Rv] = Ru;
            rank_[Ru]++;
        }
        return true;
    }
}

/** Disjoint Set Union - End **/

bool compare(Edge a, Edge b)
{
    if (a.w <= b.w)
        return true;
    else
        return false;
}

int kruskalMST(vector<Edge> &edges, int V)
{
    sort(edges.begin(), edges.end(), compare);

    for (int i = 0; i < V; i++) ///
        makeSet(i);

    int mstCost = 0;

    for (Edge e : edges)
    {
        bool unionDone = Union(e.u, e.v);
        if (unionDone == true)
        {
            cout << e.u << " " << e.v << endl;
            mstCost = mstCost + e.w;
        }
    }

    return mstCost;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<Edge> edges(E);

    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int mstCost = kruskalMST(edges, V);
    cout << mstCost << endl;

    return 0;
}