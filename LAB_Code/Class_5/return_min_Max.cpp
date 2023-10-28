//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl; // NewLine
using namespace std;

pair<int, int> minMax(vector<int> &arr, int i)
{
    int mn = arr[i];
    int mx = arr[i];

    if (i == arr.size() - 1)
        return {mx, mn}; 
    else
    {
        return {max(mx, minMax(arr, i + 1).first), min(mn, minMax(arr, i + 1).second)};
    }
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    pair<int, int> ans = minMax(arr, 0);

    cout << "max " << ans.first << nl;
    cout << "min " << ans.second << nl;

    CRACKED;
}