
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
using namespace std;

const int N = 1e5 + 2;
int dpTable[N];

int fib(int n) /// Bottom Up (Iterative Method)
{
    dpTable[1] = 0; ///-->  base case
    dpTable[2] = 1; ///-->  base case

    for (int i = 3; i <= n; i++)
    {
        dpTable[i] = dpTable[i - 1] + dpTable[i - 2];
    }

    return dpTable[n];
}

int32_t main()
{
    int n;
    cin >> n;

    cout << "\nFibonacci series " << n << "th element is : " << fib(n) << nl << nl;

    CRACKED;
}
