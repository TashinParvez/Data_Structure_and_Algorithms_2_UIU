//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl; // NewLine
using namespace std;

double calculatePower(int a, int b)
{
    if (b == 0)
        return 1;
    else if (b < 0)
    {
        b*=-1;
        return 1/(calculatePower(a, b));
    }
    else 
        return a * calculatePower(a, b - 1);
}

int32_t main()
{
    int a, b; 
    cin >> a >> b;

    double ans = calculatePower(a, b);
    cout << "a to the power b =  " << ans << nl;

    CRACKED;
}
