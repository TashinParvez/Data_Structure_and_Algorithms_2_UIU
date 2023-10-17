//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl; // NewLine
using namespace std;

int CountDigits(int n)
{
    if (n / 10 == 0)
        return 1;
    else
    {
        return 1 + CountDigits(n / 10);
    }
}

int32_t main()
{
    int n;
    cin >> n;

    int ans = CountDigits(n);
    cout << "CountDigits =  " << ans << nl;

    CRACKED;
}
