
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

int dpTable[1000][1000]; /// just use for total_use_Coin

#define notset -1

pair<int, int> coinChange(vector<int> coins, int amount_needTo_make, int coinsItake, int totalCoinsCanTake)
{

    pair<int, int> ans;

    if (dpTable[amount_needTo_make][coinsItake] != notset)
    {
        return {0, dpTable[amount_needTo_make][coinsItake]};
    }

    int createamount = -1;
    int usedCoins = coinsItake;

    ans.first = createamount;
    ans.second = usedCoins;

    if (amount_needTo_make == 0)
    {

        pair<int, int> ans;
        return {0, coinsItake};

        ///   amount_needTo_make , tatal_used_coin
        ///          0            ,          0

        // return 1;  /// normal coin change
    }

    if (coinsItake > totalCoinsCanTake)
    {
        dpTable[amount_needTo_make][coinsItake] = 100000;

        return {0, dpTable[amount_needTo_make][coinsItake]};
    }

    for (auto i : coins)
    {
        if (i > amount_needTo_make)
        {
            continue;
        }
        else
        {
            // int remainAmount = amount_needTo_make - i;
            // int callfriend_ = coinChange(coins, remainAmount, totalCoinsCanTake);
            // int takecoins = 1+ callfriend_;

            int remainAmount = amount_needTo_make - i;

            pair<int, int> callfriend_ = coinChange(coins, remainAmount, coinsItake + 1, totalCoinsCanTake);

            if (callfriend_.first != 0)
            {
                continue;
            }
            else /// able to make needed amount
            {
                if (callfriend_.second <= totalCoinsCanTake)
                {
                    ans.second = callfriend_.second;

                    dpTable[amount_needTo_make][coinsItake] = ans.second;

                    break;
                }
            }
        }
    }

    return ans;
}











bool cmp(int a, int b)
{
    return a > b;
}

int32_t main()
{
    int m, n;
    cin >> m >> n;

    vector<int> coins;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        coins.push_back(a);
    }
    int d;
    cin >> d;

    sort(coins.begin(), coins.end(), cmp);

    memset(dpTable, notset, sizeof(dpTable));

    pair<int, int> ans = coinChange(coins, m, 0, d);

    if (ans.first == 0 && ans.second <= d)
    {
        cout << "YES" << nl;
    }
    else
        cout << "NO" << nl;

    CRACKED;
}

/*
100 5
25 25 25 25 50
2
*/

/*

100 5
25 25 25 25 50
4


*/