
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
class Result
{
public:
    int minimum;
    int maximum;
};

Result minMax(int arr[], int s, int e) /// DnC
{
    if (e - s == 1 || s == e) /// when array have 2 elements or one element
    {
        Result result; /// we can use pair also
        result.minimum = min(arr[s], arr[e]);
        result.maximum = max(arr[s], arr[e]);
        return result;
    }
    else
    {
        int mid = s + (e - s) / 2;

        Result leftSide = minMax(arr, s, mid);      ///  calling Friend 1
        Result rightSide = minMax(arr, mid + 1, e); ///  calling Friend 2 

        Result result;
        result.maximum = max(leftSide.maximum, rightSide.maximum);
        result.minimum = min(leftSide.minimum, rightSide.minimum);

        return result;
    }
}

int32_t main()
{
    int n;

    // ///---> for user inputs
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    n = 8;
    int arr[n] = {-2, -5, 6, -2, -3, 1, 5, -6}; /// TestCase 1

    // n = 10;
    // int arr[n] = {2, 5, 8, 3, 6, 9, 1, 4, 7, 0}; /// TestCase 2

    Result result = minMax(arr, 0, n - 1);

    cout << nl;
    cout << "Minimum value " << result.minimum << nl;
    cout << "Maximum value " << result.maximum << nl;
    cout << nl;

    CRACKED;
}
