
//        ****************  Author :  Tashin.Parvez  ****************
//        ************* United International University *************
//        ****************  Updated:    27/10/23     ****************

#include <bits/stdc++.h>
using namespace std;
#define CRACKED return 0;

#define len(s) s.length()
#define deb(n) cout << "Tashin   " << #n << " = " << n << endl; // debug code
#define debt cout << "Tashin   " << endl;                       // debug code

// } Driver Code Ends
// User function template for C++
/**********************************************************************************************************************************************************************************/

class Result
{
public:
    int maxSum = 0;
    int len = 0;
    int leftindex;  /// index
    int rightIndex; /// index
    vector<int> ans;
};

Result crossingSum(int arr[], int left, int mid, int right)
{
    ///-------------------- checking left side
    Result result;
    int sum = 0;
    int lSum = 0;
    int index = mid;
    vector<int> a;

    while (index >= left) ///   It's imp to go from mid to left,
    {                     ///   bcz in Crossing sum we take left + right part consicutive value
        if (arr[index] < 0)
        {
            break;
        }
        result.len++;
        sum += arr[index];
        lSum = sum;
        result.leftindex = index;
        a.push_back(arr[index]);
        index--;
    }

    ///-------------------- checking right side
    sum = 0;
    int rSum = 0;
    index = mid + 1;
    vector<int> b;

    while (index <= right) ///   It's imp to go from mid+1 to right,
    {                      ///   bcz in Crossing sum we take left + right part consicutive value
        if (arr[index] < 0)
        {
            break;
        }
        result.len++;
        sum += arr[index];
        rSum = sum;
        result.rightIndex = index;
        b.push_back(arr[index]);
        index++;
    }

    result.maxSum = lSum + rSum;

    reverse(a.begin(), a.end());

    for (auto i : a)
    {
        result.ans.push_back(i);
    }

    for (auto i : b)
    {
        result.ans.push_back(i);
    }

    return result;
}

Result returnResult(Result a, Result b, Result h)
{
    if (a.maxSum == h.maxSum)
    {
        if (a.len > h.len)
            return a;
        else
            return h;
    }
    else if (b.maxSum == h.maxSum)
    {
        if (b.len > h.len)
            return a;
        else
            return h;
    }
    else
        return h;
}

Result maximumSubArray(int arr[], int left, int right)
{
    if (left == right)
    {
        Result result;
        if (arr[left] >= 0)
        {
            result.len++;
            result.maxSum = arr[left];
            result.leftindex = result.rightIndex = left;
            result.ans.push_back(arr[left]);
        }
        return result;
    }
    else
    {
        int mid = left + ((right - left) / 2);

        Result leftSum = maximumSubArray(arr, left, mid);
        Result rightSum = maximumSubArray(arr, mid + 1, right);
        Result crossSum = crossingSum(arr, left, mid, right);

        if (max({leftSum.maxSum, rightSum.maxSum, crossSum.maxSum}) == leftSum.maxSum)
        {
            return returnResult(rightSum, crossSum, leftSum);
        }
        else if (max({leftSum.maxSum, rightSum.maxSum, crossSum.maxSum}) == rightSum.maxSum)
            return returnResult(leftSum, crossSum, rightSum);
        else
            return returnResult(rightSum, leftSum, crossSum);
    }
}

class Solution
{
public:
    vector<int> findSubarray(int a[], int n)
    {

        vector<int> ans;

        int s = -1, e = -1, sum = -1;
        int currentSum = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= 0)
            {
                if (currentSum == -1)
                {
                    s = i;
                    currentSum = 0;
                }
                currentSum += a[i];
            }
            else
            {
                if (currentSum >= sum)
                {

                    e = i - 1;
                    currentSum = 0;
                }
            }
        }
    }
};

/*************************************************************************************************************************************************************************************************/

//{ Driver Code Starts.

void printAns(vector<int> &ans)
{
    for (auto &x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}
