
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

int32_t main()
{
    cout << "Enter num of products: ";
    int numOfProducts;
    cin >> numOfProducts;

    vector<pair<int, int>> vii; // value weight

    cout << "Enter products value and weight: ";

    for (int i = 0; i < numOfProducts; i++)
    {
        int a, b;
        cin >> a >> b; // value weight
        vii.push_back({a, b});
    }

    sort(vii.begin(), vii.end(), compare);

    // for sort check
    // for (int i = 0; i < numOfProducts; i++)
    // {
    //     cout << vii[i].first << "  " << vii[i].second << nl;
    // }
    // cout << nl;

    cout << "Enter bag size: ";
    int weight;
    cin >> weight; // bag size

    int ans = 0; // value in bag

    for (int i = 0; i < numOfProducts; i++)
    {
        if (vii[i].second <= weight)
        {
            ans += vii[i].first;
            weight -= vii[i].second;
            continue;
        }
        else
        {
            double value = (double)vii[i].first / vii[i].second;
            ans += value * weight;
            weight = 0;
            break;
        }
    }

    cout << nl << nl;
    cout << "Space remain: " << weight << nl;
    cout << "value of the bag: " << ans << nl;

    CRACKED;
}


/*

5

21 7
24 4
12 6
40 5
30 6

20


ans: 109

*/