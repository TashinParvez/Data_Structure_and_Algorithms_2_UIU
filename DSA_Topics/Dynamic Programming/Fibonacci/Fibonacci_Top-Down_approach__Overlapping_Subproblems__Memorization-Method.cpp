
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

int fib(int n) /// Top-Down Approach
{
    if (dpTable[n] != -1) ///--> Memorization
        return dpTable[n];
    else if (n == 2) /// -->  Base Case
    {
        dpTable[n] = 1;
        return dpTable[n];
    }
    else if (n == 1) /// -->  Base Case
    {
        dpTable[n] = 0;
        return dpTable[n];
    }
    else
    {
        int friend1 = fib(n - 1);
        int friend2 = fib(n - 2);
        dpTable[n] = friend1 + friend2; /// storing for reuse

        return dpTable[n];
    }
}

int32_t main()
{
    int n;
    cin >> n;

    for (int i = 0; i < N; i++)
    {
        dpTable[i] = -1;
    }

    memset(dpTable, -1, sizeof(dpTable)); /// set all value of dptable by -1

    int num = fib(n);

    cout << "\n Fibonacci series " << n << "th element is : " << num << nl << nl;

    CRACKED;
}
