
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

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    double v1 = (double)a.first / a.second; // value/weight
    double v2 = (double)b.first / b.second; // value/weight

    return v1 > v2;
}

pair<int, int> zeroOneKnapsack(vector<pair<int, int>> vii, int bagCapacity)
{
    sort(vii.begin(), vii.end(), compare);

    //// for sort check
    // for (int i = 0; i < numOfProducts; i++)
    //    cout << vii[i].first << "  " << vii[i].second << nl;
    // cout << nl;

    pair<int, int> solve; /// just for return Type

    int profit = 0;

    for (int i = 0; i < vii.size(); i++)
    {
        if (vii[i].second > bagCapacity)
        {
            continue;
        }
        else if (vii[i].second <= bagCapacity)
        {
            profit += vii[i].first;
            bagCapacity -= vii[i].second;
        }
    }

    solve.first = bagCapacity; /// Bag remain capacity
    solve.second = profit;     /// total Profit

    return solve;
}

int32_t main()
{
    cout << "Enter num of products: ";
    int numOfProducts;
    cin >> numOfProducts;

    vector<pair<int, int>> vii; // value & weight

    cout << "Enter products value and weight: ";

    for (int i = 0; i < numOfProducts; i++)
    {
        int a, b;
        cin >> a >> b; // value & weight
        vii.push_back({a, b});
    }

    cout << "Enter bag size: ";
    int bagCapacity;
    cin >> bagCapacity; // bag size

    pair<int, int> solve = zeroOneKnapsack(vii, bagCapacity); /// call zeroOne Knapsack Func

    cout << nl << nl;
    cout << "Space remain: " << solve.first << nl;
    cout << "value of the bag: " << solve.second << nl;

    CRACKED;
}

/*

4

1 1
4 3
5 4
7 5

7



*/