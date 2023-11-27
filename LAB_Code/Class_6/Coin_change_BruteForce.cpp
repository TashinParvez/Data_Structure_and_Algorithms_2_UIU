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

// int coinChange(vector<int> coins, int amount)
// {
//     if (amount == 0)
//         return 0;

//     int numberOfCoins = INT_MAX;
//     for (int i = 0; i < coins.size(); i++)
//     {
//         int currentCoin = coins[i];
//         if (currentCoin > amount) // for example: coin = 25, amount = 20
//             continue;
//         else
//         {
//             int remainingAmount = amount - currentCoin;
//             int friend_ = 1 + coinChange(coins, remainingAmount);

//             if (numberOfCoins > friend_)
//                 numberOfCoins = friend_;
//         }
//     }
//     return numberOfCoins;
// }

int coinChange(int it, vector<int> coins, int amount)
{

    cout << "RUNNING" << endl;

    if (amount == 0 || it == coins.size())
    {
        cout << "it = " << it << "  ";
        deb(amount);
        return 0;
    }
    else
    {
        int currentCoin = coins[it];

        if (currentCoin <= amount) /// have 2 case
        {
            cout << nl << "TASHIN ----------->>  SMALL CASE" << endl;
            int friend1 = 1 + coinChange(it, coins, amount - currentCoin); // take
            int friend2 = coinChange(it + 1, coins, amount);               // not take

            cout << "Friend1 = " << friend1 << "       Friend2 = " << friend2 << nl;
            cout << "Friend_ = " << min(friend1, friend2) << "     <<---------------------------------- this will return " << nl;
            cout<<nl;
            return min(friend1, friend2);
        }
        else /// have one case   /// big
        {
            cout << nl << "TASHIN ----------->>  BIG CASE" << endl;
            int friend1 = coinChange(it + 1, coins, amount); // take
            cout << "Friend1 = " << friend1 << "     <<------------------------------------------------ this will return " << nl;
            cout<<nl;
            return friend1;
        }
    }

    // int numberOfCoins = INT_MAX;
    // for (int i = 0; i < coins.size(); i++)
    // {
    //     int currentCoin = coins[i];
    //     if (currentCoin > amount) // for example: coin = 25, amount = 20
    //         continue;
    //     else
    //     {
    //         int remainingAmount = amount - currentCoin;
    //         int friend_ = 1 + coinChange(coins, remainingAmount);

    //         if (numberOfCoins > friend_)
    //             numberOfCoins = friend_;
    //     }
    // }
    // return numberOfCoins;
}

int main()
{
    vector<int> coins{25, 10, 1};
    // int result = coinChange(coins, 157);

    int result = coinChange(0, coins, 30);
    cout << result << endl;
    return 0;
}