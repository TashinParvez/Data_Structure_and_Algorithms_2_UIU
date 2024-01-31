
//        ****************  Author :  Tashin.Parvez  ****************
//        ************* United International University *************
//        ****************  Updated:    27/10/23     ****************

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
#define int long long
using namespace std;

const int N = 1e5 + 2;
int dpTable[N];

int tetranacci(int n) /// Bottom Up (Iterative Method)
{
    for (int i = 5; i <= n; i++)
    {
        dpTable[i] = dpTable[i - 1] + dpTable[i - 2] + dpTable[i - 3] + dpTable[i - 4];
    }

    return dpTable[n];
}

int32_t main()
{
    int n = 4;
    for (int i = 1; i <= n; i++)
    {
        cin >> dpTable[i];
    }
    cin >> n;

    cout << tetranacci(n) << nl;

    CRACKED;
}
