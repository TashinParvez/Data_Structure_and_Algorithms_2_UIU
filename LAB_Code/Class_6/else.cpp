#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> coins, int amount)
{
    // cout << "TASHIN"  << endl;
    if (amount == 0)
        return 0;

    int numberOfCoins = INT_MAX;

    for (int i = 0; i < coins.size(); i++)
    {
        int currentCoin = coins[i];
        if (currentCoin > amount) // for example: coin = 25, amount = 20
            continue;
        else
        {
            int remainingAmount = amount - currentCoin;
            int friend_ = 1 + coinChange(coins, remainingAmount);

            if (numberOfCoins > friend_)
                numberOfCoins = friend_; 
        }
    }
    return numberOfCoins;
}

int main()
{
    vector<int> coins{50, 30, 10, 5, 2};
    int result = coinChange(coins, 10);
    cout << result << endl;
    return 0;
}