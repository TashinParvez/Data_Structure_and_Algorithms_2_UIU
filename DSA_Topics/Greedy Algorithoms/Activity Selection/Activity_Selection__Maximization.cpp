
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

bool comperator(vector<int> &v1, vector<int> &v2)
{
    ///----->   Basic Code
    // if (v1[1] < v2[1])
    //     return true;
    // else
    //     return false;

    ///----->   Optimized
    return v1[1] < v2[1];
}

int32_t main()
{
    cout << "Enter total tasks: " << nl;
    int n;
    cin >> n;

    vector<vector<int>> vii(n); /// 2D vector = each index represent another vector(start time, end time)

    cout << "Enter n tasks start and end times: " << nl;
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        vii.push_back({start, end});
    }

    sort(vii.begin(), vii.end(), comperator); // ascending order based on end time

    // lamda function [custome comperator]
    // sort(vii.begin(), vii.end(), [&](vector<int> a, vector<int> b)
    //      { return a[1] < b[1]; });

    int taskTaken = 1;
    int endTime = vii[0][1];
    for (int i = 1; i < n; i++)
    {
        if (vii[i][0] >= endTime)
        {
            taskTaken++;
            endTime = vii[i][1];
        }
    }

    cout << "Task Taken " << taskTaken << nl;

    CRACKED;
}
