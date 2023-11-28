
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

int coinChangeNaive(vector<int> coins, int amount)
{
    if (amount == 0)
        return 0;

    int minCoins = -1;

    for (auto i : coins)
    {
        // cout << "Taken: " << amount / i << "  Coin: " << i << nl;
        if (i > amount)
        {
            continue;
        }
        else
        {
            int remainAmount = amount - i;
            int friend_ = coinChangeNaive(coins, remainAmount);

            if (minCoins == -1)
            {
                minCoins = friend_ + 1;
            }
            else if (friend_ + 1 < minCoins)
            {
                minCoins = friend_ + 1;
            }
        }
    }
    return minCoins;
}

pair<int, int> coinChangeGreedy(vector<int> coins, int amount)
{
    int count = 0;

    for (auto i : coins)
    {
        cout << "Taken: " << amount / i << "  Coin: " << i << nl;

        count += amount / i;
        amount -= (amount / i) * i;
    }
    return {amount, count};
}

int main()
{
    int totalCoins;
    cout << "Enter numofCoins: ";
    cin >> totalCoins;

    vector<int> coins;
    cout << "Enter all coins: ";
    for (auto i = 0; i < totalCoins; i++)
    {
        int x;
        cin >> x;
        coins.push_back(x);
    }

    sort(coins.begin(), coins.end(), greater<int>()); // decending order Sort

    cout << "Enter amount to create: ";
    int amount;
    cin >> amount;
    cout << nl;

    pair<int, int> pr = coinChangeGreedy(coins, amount);
    cout << "Greedy Approach: " << nl;
    cout << nl << "Remain Amount: " << pr.first << nl << "Total coins taken: " << pr.second << nl << nl;

    // cout << nl << nl;

    int pr2 = coinChangeNaive(coins, amount);
    cout << "Naive Approach: " << nl;
    cout << nl << "Total coins taken: " << pr2 << nl << nl;

    CRACKED;
}

/*
Case : 1

10
1000
500
200
100
50
20
10
5
2
1

52727

*/

/*
Case : 2

3
25
10
1

30


*/