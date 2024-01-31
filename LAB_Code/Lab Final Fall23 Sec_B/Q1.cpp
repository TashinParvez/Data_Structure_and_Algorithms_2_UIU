
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

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return a.second < b.second;
}

int parent[10000];
int rank__[10000];

void makeset(int v)
{
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
        rank__[i] = 0;
    }
}

int findParent(int n)
{
    if (parent[n] == n)
        return n;
    else
    {
        int frie = findParent(parent[n]);
        parent[n] = frie;
        return frie;
    }
}

bool unionSet(int u, int v)
{
    u = findParent(u);
    v = findParent(v);

    if (u == v)
        return true; ///  cant take
    else
    {
        if (rank__[u] > rank__[v])
        {
            parent[v] = u;
        }
        else if (rank__[v] > rank__[u])
        {
            parent[u] = v;
        }
        else
        {
            rank__[u]++;
            parent[v] = u;
        }
        return false; /// take this
    }
}

bool kruskalsAlgo(vector<pair<pair<int, int>, int>> &edges, int v, int amount)
{
    sort(edges.begin(), edges.end(), cmp);

    makeset(v);

    int gopalCost = 0;

    for (auto i : edges)
    {
        int u = i.first.first;
        int v = i.first.second;

        bool take = unionSet(u, v);

        if (take == false)
        {
            // cout << u << "--> " << v << nl; // debug
            gopalCost += i.second;
        }
    }

    if (gopalCost <= amount)
    {
        // cout << gopalCost << nl; // debug
        return true;
    }
    else
        return false;
}

int32_t main()
{

    int v, e;
    cin >> v >> e;
    vector<pair<pair<int, int>, int>> edges;

    for (int i = 0; i < e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({{x, y}, w});
    }

    int amount;
    cin >> amount;

    bool output_ = kruskalsAlgo(edges, v, amount);

    if (output_ == true)
    {
        cout << "YES" << nl;
    }
    else
    {
        cout << "NO" << nl;
    }

    CRACKED;
}

/*

4 5

0 1 200
1 2 700
0 3 50
1 2 800
1 3 100

900


*/

/*

4 5
0 1 200
0 2 700
0 3 50
1 2 800
1 3 100

500

*/