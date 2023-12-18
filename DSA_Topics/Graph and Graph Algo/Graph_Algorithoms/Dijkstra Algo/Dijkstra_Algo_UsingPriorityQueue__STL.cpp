
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

/*************************************************************************************************************************/

class Solution
{
public:
    vector<int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        vector<int> distance(v);
        vector<int> visited(v);
        vector<int> parent(v);

        for (int i = 0; i < v; i++)
        {
            visited[i] = 0;
            parent[i] = i;
            distance[i] = INT_MAX; /// not reachable
        }
        distance[s] = 0;

        auto cmp = [&](pair<int, int> a, pair<int, int> b)
        {
            return a.second > b.second;
        };

        ///               edge , distance from a perticular node
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> Q(cmp);
        Q.push({s, distance[s]});

        while (Q.empty() == false)
        {
            pair<int, int> temp = Q.top();
            Q.pop();

            int u = temp.first;
            int dis = temp.second;

            if (visited[u] == 1)
                continue;
            else
                visited[u] = 1;

            for (auto i : adj[u])
            {
                int v = i[0];
                int v_dis = i[1];

                if (distance[v] > dis + v_dis)
                {
                    distance[v] = dis + v_dis;
                    Q.push({v, distance[v]});
                    parent[v] = u;
                }
            }
        }

        return distance;
    }
};
