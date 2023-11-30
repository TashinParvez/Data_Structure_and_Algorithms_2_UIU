
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

Result minMax(int arr[], int index, int lastIndex)
{
    if (index == lastIndex) // checking is it last index or not
    {
        Result result;
        result.minimum = arr[index];
        result.maximum = arr[index];
        return result;
    }
    else
    {
        Result friend_ = minMax(arr, index + 1, lastIndex); /// Calling a Friend

        Result result;
        result.minimum = min(arr[index], friend_.minimum);
        result.maximum = max(arr[index], friend_.maximum);
        return result;
    }
}

int32_t main()
{
    int n;

    // //--> for user inputs
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    n = 8;
    int arr[n] = {-2, -5, 6, -2, -3, 1, 5, -6};

    // n = 10;
    // int arr[n] = {2, 5, 8, 3, 6, 9, 1, 4, 7, 0};

    Result result = minMax(arr, 0, n - 1);

    cout << nl;
    cout << "Minimum value " << result.minimum << nl;
    cout << "Maximum value " << result.maximum << nl;
    cout << nl;

    CRACKED;
}
