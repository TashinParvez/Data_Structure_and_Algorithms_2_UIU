#include <bits/stdc++.h>
using namespace std;

int func(vector<int> &num, int x, vector<int> &dptable)
{
    if (x == 0)
        return 0;

    else if (x < 0)
        return INT_MAX;

    else if (dptable[x] != -1)
        return dptable[x];

    int mini = INT_MAX;

    for (auto i : num)
    {
        int friend_ = func(num, x - i, dptable);

        if (friend_ != INT_MAX)
            mini = min(mini, 1 + friend_);
    }

    dptable[x] = mini;
    return mini;
}

int minimumElements(vector<int> &num, int x)
{
    vector<int> dptable(x + 1, -1);

    int ans = func(num, x, dptable);

    if (ans != INT_MAX)
    {
        return ans;
    }
    else
        return -1;
}