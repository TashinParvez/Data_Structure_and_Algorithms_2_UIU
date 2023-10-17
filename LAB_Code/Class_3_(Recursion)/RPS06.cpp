//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl; // NewLine
using namespace std;

int Fibonacci(int n)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
        return 1;

    return Fibonacci(n - 1) + Fibonacci(n - 2); 
}

int32_t main()
{
    int n;
    cin >> n;

    cout << "Fibonacci =  " << Fibonacci(n) << nl;

    CRACKED;
}
