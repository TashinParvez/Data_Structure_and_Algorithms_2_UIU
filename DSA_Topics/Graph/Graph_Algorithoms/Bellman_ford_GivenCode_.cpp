/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, w;
};

const int INF = 0x7f7f7f7f;

void pathPrint(int node, int parent[])
{
    if (parent[node] == node)
    {
        cout << node;
        return;
    }
    else
    {
        pathPrint(parent[node], parent);
        cout << " -> " << node;
    }
}

void printArray(int arr[], int n, int parent[])
{
    for (int i = 0; i < n; i++)
    {
        cout << i << " --> " << arr[i] << " Path: ";
        pathPrint(i, parent);
        cout << endl;
    }
    cout << endl;
}

void bellmanFord(vector<Edge> edges, int V, int source)
{
    int distance[V];
    memset(distance, INF, sizeof(distance));
    distance[source] = 0;
    int parent[V];
    for (int i = 0; i < V; i++)
        parent[i] = i;

    for (int i = 1; i <= V - 1; i++)
    {
        bool updated = false;
        for (Edge edge : edges)
        {
            if (distance[edge.v] > distance[edge.u] + edge.w)
            {
                distance[edge.v] = distance[edge.u] + edge.w;
                parent[edge.v] = edge.u;
                updated = true;
            }
        }
        if (updated == false)
        {
            printArray(distance, V, parent);
            return;
        }
    }

    for (Edge edge : edges)
    {
        if (distance[edge.v] > distance[edge.u] + edge.w)
        {
            distance[edge.v] = distance[edge.u] + edge.w;
            cout << "Negative Cycle Exist\n";
            return;
        }
    }

    printArray(distance, V, parent);
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
    int source;
    cin >> source;
    bellmanFord(edges, V, source);
    return 0;
}