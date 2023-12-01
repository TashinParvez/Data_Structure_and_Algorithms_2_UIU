
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

int crossingSumResult(vector<int> arr, int s, int e, int mid)
{
    int output;

    //------------------ left side
    int lSumOutput = arr[mid];
    int currentLsum = arr[mid];

    int index = mid - 1; // mid to start

    while (index >= s)
    {
        currentLsum += arr[index];
        if (currentLsum > lSumOutput)
        {
            lSumOutput = currentLsum;
        }
        index--;
    }

    //------------------ right side

    int rSumOutput = arr[mid + 1];
    int currentRsum = arr[mid + 1];

    index = (mid + 1) + 1; // mid to start

    while (index <= e)
    {
        currentRsum += arr[index];
        if (currentRsum > rSumOutput)
        {
            rSumOutput = currentRsum;
        }
        index++;
    }

    return rSumOutput + lSumOutput;
}

int maximumSubArray(vector<int> arr, int s, int e)
{
    if (s == e) // base case
    {
        return arr[s];
    }

    int midIndex = s + (e - s) / 2;

    int leftSum = maximumSubArray(arr, s, midIndex);

    int crossingSum = crossingSumResult(arr, s, e, midIndex);

    int rightSum = maximumSubArray(arr, midIndex + 1, e);

    return max({leftSum, rightSum, crossingSum});
}

int32_t main()
{

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int maxiSum = maximumSubArray(arr, 0, n - 1);

    cout << maxiSum << nl;

    CRACKED;
}

/*

9
-2 1 -3 4 -1 2 1 -5 4

*/