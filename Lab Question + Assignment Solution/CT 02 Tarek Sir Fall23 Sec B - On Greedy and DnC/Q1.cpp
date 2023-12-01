
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

int tryingForLogN(vector<int> arr, int totalDistance, int maxGo)
{
    
}

int32_t main()
{

    int totalDistance;
    cin >> totalDistance;

    int maxGo;
    cin >> maxGo;

    int s;
    cin >> s;
    vector<int> stops(s);

    for (int i = 0; i < s; i++)
    {
        cin >> stops[i];
    }

    /**************************/
    int currentDistance = maxGo;
    int cnt = 0;

    for (int i = 0; i < s; i++)
    {
        if (stops[i] == currentDistance)
        {
            if (i == s - 1 && currentDistance >= totalDistance)
            {
                break;
            }
            cnt++;
            currentDistance = stops[i] + maxGo;
            if (i == s - 1 && currentDistance < totalDistance)
            {
                cout << "Cant reach The position" << nl;
                return 0;
            }
        }
        else if (stops[i] > currentDistance)
        {
            cnt++;
            currentDistance = stops[i - 1] + maxGo;
        }
    }

    cout << "Total stops " << cnt << nl;

    CRACKED;
}

/*

20
10
8
2 4 5 8 12 14 16 19


*/