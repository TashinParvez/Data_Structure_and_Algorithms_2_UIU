//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    18-08-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
#define null NULL
using namespace std;

string toggle(string s, int i, int strlen)
{
    if (i == strlen) 
        return "";
    else if (s[i] >= 'A' && s[i] <= 'Z')
        return (char)('a' + (s[i] - 'A')) + toggle(s, i + 1, strlen);
    else if (s[i] >= 'a' && s[i] <= 'z')
        return (char)('A' + (s[i] - 'a')) + toggle(s, i + 1, strlen);
    else
        return s[i] + toggle(s, i + 1, strlen);
}

int32_t main()
{
    string s;
    getline(cin, s);

    cout << toggle(s, 0, s.length()) << nl;

    CRACKED;
}
