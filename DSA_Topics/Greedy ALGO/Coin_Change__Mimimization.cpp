
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

    // for (auto i : coins)
    // {
    //     cout << i << " ";
    // }

    cout << "Enter amount to create: ";
    int amount;
    cin >> amount;

    cout << nl;
    int count = 0;

    for (auto i : coins)
    {
        cout <<  "Taken: " << amount / i <<"  Coin: " << i << nl;

        count += amount / i;
        amount -= (amount / i) * i;
    }

    cout << nl << "Remain Amount: " << amount << nl << "Total coins taken: " << count << nl << nl;

    CRACKED;
}

/*

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