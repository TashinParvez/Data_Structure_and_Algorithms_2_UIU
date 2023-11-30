
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

int coinChangeNaive(vector<int> coins, int amount) /// Bruteforce approach
{
    if (amount == 0)
        return 0;

    int minCoins = -1;

    for (auto i : coins)
    {
        // cout << "Taken: " << amount / i << "  Coin: " << i << nl;

        if (i > amount) /// Not Take
        {
            continue;
        }
        else
        {
            /// take Option Solve
            int remainAmount = amount - i;
            int friend_ = coinChangeNaive(coins, remainAmount); /// friend wwill give me left amount solution
            int totalAns = friend_ + 1;

            if (minCoins == -1) /// this will exicute when i able o take the needed amount
            {
                minCoins = totalAns;
            }
            else if (totalAns < minCoins)
            {
                minCoins = friend_ + 1;
            }
        }
        /*

           In every iteration of the for loop
           checking for the different coin take option
           means in iteration I'm checking if I need first given amount and I will pick the ith coin first
           and then call friend to solve for remaining ammount

           ///-------->>  Tarek Sir 11 Nov Class

        */
    }

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

    cout << "Enter amount to create: ";
    int amount;
    cin >> amount;
    cout << nl;

    int pr2 = coinChangeNaive(coins, amount);
    cout << "Naive Approach: " << nl;
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