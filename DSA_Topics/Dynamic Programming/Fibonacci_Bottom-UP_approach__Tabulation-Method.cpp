
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

#define int long long
const int N = 1e5 + 2;
using namespace std;

int dpTable[N];

int32_t main()
{
    int n;
    cin >> n;
    dpTable[1] = 0;
    dpTable[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        dpTable[i] = dpTable[i - 1] + dpTable[i - 2];
    }

    cout << "\n Fibonacci series " << n << "th element is : " << dpTable[n] << nl << nl;

    CRACKED;
}