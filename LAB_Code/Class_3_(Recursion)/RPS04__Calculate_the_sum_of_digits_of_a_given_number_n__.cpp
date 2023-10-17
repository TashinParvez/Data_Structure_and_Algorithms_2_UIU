//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl; // NewLine
using namespace std;

int SumOfDigits(int n)
{
    if (n / 10 == 0) 
        return n;
    else
    {
        return (n % 10) + SumOfDigits(n / 10);
    }
}

int32_t main()
{
    int n;
    cin >> n;

    int ans = SumOfDigits(n);
    cout << "SumOfDigits =  " << ans << nl;

    CRACKED;
}
