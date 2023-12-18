
//        ****************  Author :  Tashin.Parvez  ****************
//        ************* United International University *************
//        ****************  Updated:    27/10/23     ****************

//    https://www.youtube.com/watch?v=F3PNsWE6_hM

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

/*
    /// Dirrected Weighted Connected non-Negative Graph
      Single Source shortest Path
      Weighted (Non-Negative)
      Does not work on Negative Cycle
      O(E*log(V))
*/

struct Edge
{
    int v;
    int w;
};

struct Ndistance
{
    int node;
    int distance;
};

const int INF = 0x7F7F7F7F;

void pathPrint(int currentNode, int parent[])
{
    if (parent[currentNode] == currentNode)
    {
        cout << currentNode << "->";
    }
    else
    {
        pathPrint(parent[currentNode], parent);
        cout << currentNode << "->";
    }
}

void Dijkstra(vector<Edge> Graph[], int V, int source)
{
    int distance[V];

    for (int i = 0; i < V; i++) /// making unreachable
        distance[i] = INF;
    distance[source] = 0;

    int parent[V];

    for (int i = 0; i < V; i++) /// make set func
        parent[i] = i;

    auto compare = [&](Ndistance a, Ndistance b) /// lamda func for compare
    {
        if (a.distance <= b.distance) /// check the return type
                                      /// priority queue returen type is diff from other's normal logic
            return false;
        else
            return true;
    };

    priority_queue<Ndistance, vector<Ndistance>, decltype(compare)> PQ(compare);

    PQ.push({source, distance[source]}); /// source and source to source distance

    while (PQ.empty() == false)
    {
        Ndistance temp = PQ.top(); /// take the lowest disteance element from the current pos

        int currentNode = temp.node;            /// reached node become Current Node
        int distanceFormSource = temp.distance; /// (source to u)
        PQ.pop();

        for (Edge neighbor : Graph[currentNode]) /// node - weight ( (to & Cost )
        {
            ///      in Record       >    (source to u)   +  (u to v)
            if (distance[neighbor.v] > distanceFormSource + neighbor.w)
            {
                distance[neighbor.v] = distanceFormSource + neighbor.w; /// Update Record

                PQ.push({neighbor.v, distance[neighbor.v]}); /// push in queue

                parent[neighbor.v] = currentNode; /// Update parent
            }
        }
    }

    /// Algo done

    /**************** Print To See Path's and Weights ***********************/

    cout << "\nV : W :  Path" << endl;
    cout << "------------------" << endl;

    for (int i = 0; i < V; i++)
    {
        cout << i << " : ";
        cout << distance[i] << "  :  ";
        pathPrint(i, parent);
        cout << endl;
    }
    cout << endl;
}

int main()
{

    /// Dirrected Weighted Connected non-Negative Graph
    int V, E;
    cout << "\nEnter total vertex and total edges: ";
    cin >> V >> E;

    vector<Edge> Graph[V]; /// node & distance

    cout << "Enter all edges form u to v and weight: " << nl;

    for (int i = 0; i < E; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;

        Graph[from].push_back({to, cost}); /// from er index e push back (to & Cost)
    }

    int source;
    cout << "Enter Source: ";
    cin >> source;

    Dijkstra(Graph, V, source);

    return 0;
}

/*


6 8

0 1 10
0 2 1
1 3 3
2 1 2
2 3 7
3 4 2
4 5 2
3 5 3

0

*/