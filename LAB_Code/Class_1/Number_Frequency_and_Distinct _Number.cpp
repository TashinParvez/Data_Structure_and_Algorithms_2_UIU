//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl; // NewLine
#define setDec(x) fixed << setprecision(x)
using namespace std;

int32_t main()
{
    int arr[10000] = {0};
    int n;
    cout << "Enter Total number: ";
    cin >> n;
    int a;
    cout << "Enter Numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr[a]++;
    }

    for (int i = 0; i < 10000; i++)
    {
        if (arr[i] > 0)
            cout << i << ",";
    }
    
    cout << nl;
    cout << nl;
    for (int i = 0; i < 10000; i++)
    {
        if (arr[i] > 0)
            cout << i << "  " << arr[i] << nl;
    }

    CRACKED;
}
