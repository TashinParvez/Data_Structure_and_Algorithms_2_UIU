
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

int dpTable[1000];

int coinChange_DP(vector<int> coins, int amount) /// Bruteforce approach
{
    if (amount == 0)
        return 0;
    else if (dpTable[amount] != -1)
        return dpTable[amount];

    int minCoins = -1;

    for (auto i : coins)
    {
        /// cout << "Taken: " << amount / i << "  Coin: " << i << nl;

        if (i > amount)
        {
            continue;
        }
        else
        {
            int remainAmount = amount - i;
            int friend_ = coinChange_DP(coins, remainAmount); /// friend wwill give me left amount solution
            int totalAns = friend_ + 1;

            if (minCoins == -1) /// this will exicute when i able o take the needed amount
            {
                minCoins = totalAns;
            }
            else if (totalAns < minCoins) /// here we are doing our theory take not take min part option
            {                             /// because in minCoins I have not take part
                minCoins = friend_ + 1;
            }
        }
        /*


           For every every amount we have options to take as many coin's We have
           -->  Let say I have  ( 5, 2, 1 )   coin's
           -->  so if I want to create 20
           -->  first I have 3 option  [Needed 20]
           -->  I have 3 option  [Needed 15]


           In every iteration of the for loop
           Checking for the different coin take option [In for loop Iteration : Amount needed is not changing]
           we are checking the other options.

           means in iteration I'm checking if I need first given amount and I will pick the ith coin first
           and then call friend to solve for remaining ammount.
           in second itearation I have the same need ammount but I'm cchoosing the second coin first then asking friend to help for the rest


           ///-------->>  Tarek Sir 11 Nov Class

        */
    }

    dpTable[amount] = minCoins;
    return minCoins;
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

    sort(coins.begin(), coins.end(), greater<int>()); /// decending order Sort

    memset(dpTable, -1, sizeof(dpTable));

    cout << "Enter amount to create: ";
    int amount;
    cin >> amount;
    cout << nl;

    int pr2 = coinChange_DP(coins, amount);
    cout << nl << "Total coins taken: " << pr2 << nl << nl;

    CRACKED;
}

/*


3
25
10
1

30


*/