//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    18-08-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
#define null NULL
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        int currentElement = arr[i];
        bool previouslyFound = false;

        for (int j = 0; j <= (i - 1); j++)
        {
            if (arr[j] == currentElement)
            {
                previouslyFound = true;
                break;
            }
        }

        if (previouslyFound == false)
            cout << currentElement << " ";
    }
    cout << nl;
    CRACKED;
}
