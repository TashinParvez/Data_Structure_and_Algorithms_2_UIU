
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
#define debt cout << "Tashin   " << endl;                       // debug code

using namespace std;

void DNC(vector<int> &arr, int s, int e)
{
    if (s == e || e - s == 1)
    {
        return;
    }
    else
    {
        int mid = s + (e - s) / 2;
        if (arr[mid - 1] + arr[mid + 1] == 2 * arr[mid])
        {
            swap(arr[mid - 1], arr[mid]);
            DNC(arr, s, mid - 1);
            DNC(arr, mid + 1, e);
        }
    }
}

int32_t main()
{
    while (1)
    {
        cout << "Input N : ";
        int n;
        cin >> n;
        if (n == 0)
            break;

        vector<int> arr;
        for (size_t i = 1; i <= n; i++)
        {
            arr.push_back(i);
        }

        DNC(arr, 0, n - 1);

        for (size_t i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << nl;
    }

    CRACKED;
}
