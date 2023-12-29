//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    18-08-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
#define null NULL
using namespace std;

/** Disjoint Set - With Heuristic  **/

int parent[107]; /// To store parents
int rank_[107];  /// store level

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
        /*    Path Comperssion (Heuristic PART)      */
        int friend_ = findSet(parent[x]);
        parent[x] = friend_;
        return friend_;
    }
}

bool Union(int u, int v)
{
    int Ru = findSet(u); /// get parent
    int Rv = findSet(v);

    if (Ru == Rv)
        return false; /// already Connected
    else
    {
        /*       Rank By Union (Heuristic Part)          */

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

int32_t main()
{
    // main func
}
