//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    18-08-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
#define null NULL
using namespace std;

void factorial(int n)
{
    cout << n << "! = ";
    int multiple = 1;
    for (int i = n; i >= 1; i--)
    {
        multiple *= i;
        if (i == 1)
            cout << i << " ";
        else
            cout << i << " X ";
    }
    cout << " = " << multiple << nl;

    return;
}

int32_t main()
{
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        factorial(i);
    }

    CRACKED;
}
