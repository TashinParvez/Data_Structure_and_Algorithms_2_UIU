//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl; // NewLine
using namespace std;

void print1toN(int i, int n)
{
    if (i > n)
        return;
    else 
    {
        cout << i << nl;
        return print1toN(i + 1, n);
    }
}

void UsingOnlyN(int n)
{
    if (n == 0)
        return;
    else
    {
        UsingOnlyN(n - 1);
        cout << n << nl;
    }
}

int32_t main()
{
    int n;
    cin >> n;
    
    print1toN(1, n);
    cout << nl;
    cout << nl;
    UsingOnlyN(n);

    CRACKED;
}