//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    18-08-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
#define null NULL
using namespace std;

string func(string s, int i, int strlen)
{
    if (i == strlen)
        return "";
    else if (s[i] == ' ')
        return "" + func(s, i + 1, strlen);
    else if (s[i] >= 'A' && s[i] <= 'Z') 
        return (char)('a' + (s[i] - 'A')) + func(s, i + 1, strlen);
    else
        return s[i] + func(s, i + 1, strlen);
}

int32_t main()
{
    string s;
    getline(cin, s);

    cout << func(s, 0, s.length()) << nl;

    CRACKED;
}
