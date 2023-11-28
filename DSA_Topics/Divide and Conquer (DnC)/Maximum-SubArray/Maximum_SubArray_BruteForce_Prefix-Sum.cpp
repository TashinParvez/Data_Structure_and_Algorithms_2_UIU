
//        ****************  Author :  Tashin.Parvez  ****************
//        ************* United International University *************
//        ****************  Updated:    27/10/23     ****************

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
#define null NULL
#define sp " " // space
#define setDec(x) fixed << setprecision(x)
#define len(s) s.length()
#define deb(n) cout << "Tashin   " << #n << " = " << n << endl; // debug code

using namespace std;

int32_t main()
{
    int n;

    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    // n = 8;
    // int arr[8] = {-2, -5, 6, -2, -3, 1, 5, -6};

    n = 5;
    int arr[n] = {1, 2, 3, 4, 5};

    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum > maxSum)
                maxSum = sum;
        }
    }

    cout << "Maximum Sum: " << maxSum << nl;

    CRACKED;
}
