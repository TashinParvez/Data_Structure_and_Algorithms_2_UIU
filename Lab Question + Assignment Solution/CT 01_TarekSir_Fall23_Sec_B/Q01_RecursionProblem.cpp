//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl; // NewLine
using namespace std;

int taskTakeTimes(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return taskTakeTimes(n - 1) + taskTakeTimes(n - 2);
}

int32_t main()
{
    int n;
    cin >> n;

    cout << taskTakeTimes(n) << nl;

    CRACKED;
}