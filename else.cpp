
//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    21-06-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;

#define PI 3.14159265358979323846

// I/O :
#define loop(n) for (int i = 0; i < n; i++) // 0 to n Input or Output
#define output(x) cout << x << nl           // out
#define printarray(arr, len)      \
    for (int i = 0; i < len; i++) \
    {                             \
        cout << arr[i] << " ";    \
        if (i + 1 == len)         \
            cout << endl;         \
    } // array print

#define sq(x) ((x) * (x)) // x^2  square
#define len(s) s.length()
#define setDec(x) fixed << setprecision(x)

#define YES printf("YES\n")
#define Yes printf("Yes\n")
#define NO printf("NO\n")
#define No printf("No\n")

using namespace std;

/*
    int n; cin>>n;
    int arr[n];
    for(auto &v : arr) cin>>v;


    if(!(i&1))   //-------------- EVEN  (for even --->> i&1 == 0)
        cout<<i<<nl;

*/

void solution()
{

    /**
     *
     open eye means 1
     closed eye means 0
     left eye is the most significative eye
     right eye is the least significative eye

     Every blink this number is added and
     when the crow screams,the sum is a result.

     */

    int sum = 0;
    string s;
    while (getline(cin, s))
    {
        if (s == "caw caw" || s == "caw")
            break;
        int temp = 0;
        if (s[0] == '*')
            temp += 4;
        if (s[1] == '*')
            temp += 2;
        if (s[2] == '*')
            temp += 1;

        sum += temp;
    }
    cout << sum << endl;
}

int main()
{

    // #ifdef TashinParvez
    //     Read("input.txt");
    //   //  Write("output.txt");
    // #endif // TashinParvez

    int t = 3;
    int c = 1;

    while (t--)
    {
        solution();
    }

    CRACKED;
}
