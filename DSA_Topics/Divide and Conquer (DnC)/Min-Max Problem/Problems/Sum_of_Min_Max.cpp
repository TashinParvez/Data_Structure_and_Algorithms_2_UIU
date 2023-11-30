// https://www.geeksforgeeks.org/problems/max-min/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

//        ****************  Author :  Tashin.Parvez  ****************
//        ************* United International University *************
//        ****************  Updated:    27/10/23     ****************

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
using namespace std;

class Result
{
public:
    int mn;
    int mx;
};

Result minMax(int arr[], int s, int e)
{
    if (s == e || e - s == 1)
    {
        Result r;
        r.mn = min(arr[s], arr[e]);
        r.mx = max(arr[s], arr[e]);

        return r;
    }
    else
    {
        int mid = s + (e - s) / 2;
        Result f1 = minMax(arr, s, mid);
        Result f2 = minMax(arr, mid + 1, e);

        Result r;
        r.mn = min(f1.mn, f2.mn);
        r.mx = max(f1.mx, f2.mx);
        return r;
    }
}

class Solution
{
public:
    int findSum(int A[], int N)
    {
        Result result = minMax(A, 0, N - 1);
        return result.mn + result.mx;       /// here is the thing
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        int ans = ob.findSum(arr, n);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends