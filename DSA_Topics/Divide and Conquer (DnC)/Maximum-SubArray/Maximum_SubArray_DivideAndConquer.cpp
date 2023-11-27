
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
#define debT() cout << "Tashin" << nl;                          // debug code

using namespace std;
class Result
{
public:
    int maxSum;
    int leftindex;
    int rightIndex;
};

Result crossingSum(int arr[], int left, int mid, int right)
{
    // checking left side
    Result result;
    int sum = 0;
    int lSum = INT_MIN;
    int index = mid;
    while (index >= left)
    {
        sum += arr[index];
        if (sum > lSum)
        {
            lSum = sum;
            result.leftindex = index;
        }
        index--;
    }

    // checking right side
    sum = 0;
    int rSum = INT_MIN;
    index = mid + 1;
    while (index <= right)
    {
        sum += arr[index];
        if (sum > rSum)
        {
            rSum = sum;
            result.rightIndex = index;
        }
        index++;
    }

    result.maxSum = lSum + rSum;

    return result;
}

Result maximumSubArray(int arr[], int left, int right)
{
    if (left == right)
    {
        Result result;
        result.maxSum = arr[left];
        result.leftindex = result.rightIndex = left;

        return result;
    }
    else
    {
        int mid = left + ((right - left) / 2);

        Result leftSum = maximumSubArray(arr, left, mid);
        Result rightSum = maximumSubArray(arr, mid + 1, right);
        Result crossSum = crossingSum(arr, left, mid, right);

        // //--> Basic code
        // if (leftSum.maxSum >= rightSum.maxSum && leftSum.maxSum >= crossSum.maxSum)
        //     return leftSum;
        // else if (rightSum.maxSum >= leftSum.maxSum && rightSum.maxSum >= crossSum.maxSum)
        //     return rightSum;
        // else
        //     return crossSum;

        if (max({leftSum.maxSum, rightSum.maxSum, crossSum.maxSum}) == leftSum.maxSum)
            return leftSum;
        else if (max({leftSum.maxSum, rightSum.maxSum, crossSum.maxSum}) == rightSum.maxSum)
            return rightSum;
        else
            return crossSum;
    }
}

int32_t main()
{
    int n;
    n = 8;

    // //--> for user inputs
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    // int arr[n] = {-2, -5, 6, -2, -3, 1, 5, -6};
    n = 5;
    int arr[n] = {1, 2, 3, 4, 5};

    Result result = maximumSubArray(arr, 0, n - 1);

    cout << "Maximum Sum: " << result.maxSum << endl;
    cout << "Index: " << result.leftindex << " " << result.rightIndex << endl;

    CRACKED;
}
