//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl; // NewLine
using namespace std;

void printArray(int i, int n, int arr[])
{
    if (i == n)
        return;
    else
    {
        cout << arr[i] << " ";
        printArray(i + 1, n, arr);
    }
}

int32_t main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    printArray(0, sizeof(arr) / sizeof(arr[0]), arr);

    CRACKED;
}
