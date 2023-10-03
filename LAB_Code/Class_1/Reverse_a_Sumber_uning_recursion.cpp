//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl; // NewLine
#define setDec(x) fixed << setprecision(x)

using namespace std;
int reverse(int n, int ans)
{
    int temp = n % 10;
    ans *= 10;
    ans += temp;
    n = n / 10;
    if (n == 0)
        return ans;
    else
        reverse(n, ans);
}

int32_t main()
{
    int n;
    cout << "Enter a Number: ";
    cin >> n;
    cout << "Reverse Number: ";
    cout << reverse(n, 0) << nl;

    CRACKED;
}
