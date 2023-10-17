//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl; // NewLine
using namespace std;

int Sum(int n)
{
    if (n == 0)
        return 0;
    else
        return n + Sum(n - 1);
}

int32_t main()
{
    int n;
    cin >> n;

    int ans = Sum(n);
    cout << "Ans " << ans << nl;

    CRACKED;
}