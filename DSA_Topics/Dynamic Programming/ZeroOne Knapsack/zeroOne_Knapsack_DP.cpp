
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

typedef struct Products
{
    string productID;
    int weight;
    int value;
} Product;

int dpTable[100][100];
///       index  capacity

int zeroOneKnapsack_DP(vector<Product> products, int capacity, int index) //----> O(2^n)
{
    if (dpTable[index][capacity] != -1) /// memorization
        return dpTable[index][capacity];

    if (capacity == 0 || index == products.size()) /// no product remain or bag capacity = zero
    {
        dpTable[index][capacity] = 0;    /// storing
        
        return dpTable[index][capacity]; /// can't able to take Products
    }

    if (products[index].weight > capacity) /// Not Take Condition
    {
        /// Skip the current product  == Not Take
        int friend_ = zeroOneKnapsack_DP(products, capacity, index + 1); /// just increase the index
        dpTable[index][capacity] = friend_;                              /// storing

        return dpTable[index][capacity];
    }
    else
    {
        //
        /// take the current product
        int take = products[index].value;
        int nibo_andFriend = zeroOneKnapsack_DP(products, capacity - products[index].weight, index + 1); // calling friend [increase index  and  capacity decrease]
        take += nibo_andFriend;

        //
        /// Skip the current product = Not Take
        int notTake = 0;
        int niboNa_andFriend = zeroOneKnapsack_DP(products, capacity, index + 1); // calling friend  [just --> increase index]
        notTake += niboNa_andFriend;

        dpTable[index][capacity] = max(take, notTake); /// takeing the max profit from (take or notTake) /// storing

        return dpTable[index][capacity];
    }
}

int32_t main()
{
    cout << "Enter num of products: ";
    int numOfProducts;
    cin >> numOfProducts;

    vector<Product> products(numOfProducts);

    cout << "Enter products Id, value and weight : ";

    for (int i = 0; i < numOfProducts; i++)
    {
        getchar();
        cin >> products[i].productID;
        cin >> products[i].value;
        cin >> products[i].weight;
    }

    cout << "Enter bag size: ";
    int bagCapacity;
    cin >> bagCapacity; // bag size

    int ans;

    ///
    ///
    ///

    memset(dpTable, -1, sizeof(dpTable));

    ans = zeroOneKnapsack_DP(products, bagCapacity, 0); // value in bag
    cout << nl << "Value of the bag: " << ans << nl << nl;

    CRACKED;
}

/*

4

p1 1 1
p2 4 3
p3 5 4
p4 7 5


7


*/

/*

5
p1 1 1
p2 2 6
p3 6 8
p4 5 9
p5 3 6

11

*/

/*

4

p1 1 1
p2 4 3
p3 5 4
p4 7 5


7


*/

/*

5
p1 1 1
p2 2 6
p3 6 8
p4 5 9
p5 3 6

11

*/

/*

3
p1 60 10
p2 100 20
p3 120 30

50

*/
/*

3
P1 60 10
P2 100 20
P3 120 30

50

*/