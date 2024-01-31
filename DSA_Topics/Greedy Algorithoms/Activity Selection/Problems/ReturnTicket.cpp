
//        ****************  Author :  Tashin.Parvez  ****************
//        ************* United International University *************
//        ****************  Updated:    27/10/23     ****************

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
using namespace std;

bool activitySelection(vector<int> start, vector<int> end, int n, int amountNeed)
{
    if (start.size() == 0)
    {
        if (amountNeed == 0)
            return true;
        else
            return false;
    }

    vector<pair<int, int>> vii;

    for (auto i = 0; i < n; i++)
    {
        vii.push_back({start[i], end[i]});
    }

    sort(vii.begin(), vii.end(), [&](pair<int, int> a, pair<int, int> b)
         { return a.second < b.second; });

    int taskpicked = 1;
    int money = 10;
    int availability = vii[0].second;

    for (int i = 1; i < n; i++)
    {
        if (vii[i].first > availability)
        {
            taskpicked++;
            money += 10;
            availability = vii[i].second;
            if (amountNeed <= money)
                break;
        }
    }

    if (amountNeed <= money)
        return true;
    else
        return false;
}

int32_t main()
{

    int n;
    cin >> n;
    vector<int> start(n), end(n);

    for (int i = 0; i < n; i++)
        cin >> start[i];
    for (int i = 0; i < n; i++)
        cin >> end[i];

    int numofABCurrencyYouNeed;
    cin >> numofABCurrencyYouNeed;

    if (activitySelection(start, end, n, numofABCurrencyYouNeed))
        cout << "YES" << nl;
    else
        cout << "NO" << nl;
}


/*

4
1 3 2 5
2 4 3 6
40

*/

/*

4
1 2 3 5
2 3 4 6
30

*/