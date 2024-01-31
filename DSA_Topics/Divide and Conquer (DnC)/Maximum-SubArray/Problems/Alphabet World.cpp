
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
    int maxSum = 0;
    int leftindex;  /// index
    int rightIndex; /// index
};

Result crossingSum(string str, int left, int mid, int right)
{
    Result result;
    result.maxSum = (int)str[mid] + (int)str[mid + 1];
    result.leftindex = mid;
    result.rightIndex = mid + 1;

    return result;
}

Result maximumSubArray(string str, int left, int right)
{
    if (left == right || right - left == 1) // one/two element
    {
        Result result;
        result.maxSum = (int)str[left];
        result.leftindex = left;
        result.rightIndex = -1;
        if (left != right)
        {
            result.maxSum += (int)str[right];
            result.rightIndex = right;
        }
        return result;
    }
    else
    {
        int mid = left + ((right - left) / 2);

        Result leftSum = maximumSubArray(str, left, mid);
        Result rightSum = maximumSubArray(str, mid + 1, right);
        Result crossSum = crossingSum(str, left, mid, right);

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

    string str;
    cin >> str;

    Result result = maximumSubArray(str, 0, len(str));

    cout << "Maximum Sum: " << result.maxSum << endl;

    cout << "Taken Alphabates: ";
    if (result.leftindex != -1)
    {
        cout << str[result.leftindex];
    }
    if (result.rightIndex != -1)
    {
        cout << str[result.rightIndex];
    }
    cout << nl;

    CRACKED;
}


/*

abcdsafasxals

aAbaABzAZBA

ABSCVV
ZZZZaa
*/