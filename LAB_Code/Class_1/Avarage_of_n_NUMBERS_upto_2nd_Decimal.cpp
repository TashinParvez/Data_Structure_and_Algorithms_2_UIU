//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl; // NewLine
#define setDec(x) fixed << setprecision(x)
using namespace std;

int32_t main()
{

    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        sum += a;
    }

    cout << setDec(2) << sum / (n * 1.0) << nl;

    CRACKED;
}
