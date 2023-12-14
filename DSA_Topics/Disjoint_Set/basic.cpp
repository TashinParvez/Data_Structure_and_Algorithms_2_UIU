//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    18-08-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
#define null NULL
using namespace std;

int parent[100];

// find function
// return it's parent
int find(int a)
{
    if (parent[a] == a)
        return a;
    else
        return find(parent[a]);
}

// Union Function

void unionSet(int a, int b)
{
    int u = parent[a];
    int v = parent[b];
    if (u == v)
        cout << "They are in the same set" << nl;
    else
        parent[b] = a;
}

/** Disjoint Set Union - Start (Learn From Tarek Sir)**/

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
        else
        {
            parent[Rv] = Ru;
            rank_[Ru]++;
        }
        return true;
    }
}

/** Disjoint Set Union - End **/

int32_t main()
{
    // main func
}
