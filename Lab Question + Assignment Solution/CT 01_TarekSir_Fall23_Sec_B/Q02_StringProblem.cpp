//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl; // NewLine
using namespace std;
int countt = 0;

string password(int n, int cnt)
{
    if (n == 0)
    {
        return "";
    }
    else
    {
        int lastDigit = n % 10;
        if (lastDigit % 2 == 0) // even
        {
            cnt++;
            countt++;
            return to_string(lastDigit) + password(n / 10, 0);
        }
        else
        {
            return password(n / 10, 0);
        }
    }
}

int32_t main()
{
    int n;
    cin >> n;

    string s = password(n, 0);
    for (int i = s.length(); i >= 0; i--)
    {
        cout << s[i];
    }
    cout << "#" << countt << nl;
    CRACKED;
}