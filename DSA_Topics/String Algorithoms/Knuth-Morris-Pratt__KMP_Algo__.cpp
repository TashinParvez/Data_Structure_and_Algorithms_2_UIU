
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

vector<int> createLPS(string pattern) /// Working correctly
{
    /// acacabacacab
    vector<int> lps(pattern.length(), 0); /// Storing the position of the matched char

    int len = 0; /// Length of the previous longest prefix suffix
    int i = 1;   /// iterator

    while (i < pattern.length())
    {
        if (pattern[i] == pattern[len])
        {
            lps[i] = (len + 1);
            len++;
            i++;
        }
        else
        {
            if (len != 0)
            {
                /*
                   index = index-1;
                   index = lps[index] +1;
                */

                len = lps[len - 1];
            }
            else
            {
                lps[i] = (0);
                i++;
            }
        }
    }

    return lps;
}

void KMP_algo(string text, string pattern)
{
    vector<int> lps = createLPS(pattern);

    int i = 0; /// iterate --> text
    int j = 0; /// iterate --> pattern

    while (i < text.length())
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }

        if (j == pattern.length())
        {
            cout << "Find Match" << nl;
            break;
        }
    }
}

int32_t main()
{
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);

    KMP_algo(text, pattern);

    CRACKED;
}

/*

  Pattern: acacabacacabacacac   /// note's LPS Logic


  Pattern: abaabcabsascsaabaaabcabba

*/