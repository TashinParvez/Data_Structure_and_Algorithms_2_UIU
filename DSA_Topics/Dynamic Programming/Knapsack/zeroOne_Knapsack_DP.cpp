
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

int dpTable[1000][1000];
///       index  capacity

int zeroOneKnapsack_BruteForce(vector<Product> products, int capacity, int index) //----> O(2^n)
{
    if (capacity == 0 || index == products.size()) /// no product remain or bag capacity = zero
    {
        dpTable[index][capacity] = 0;
        return 0;
    }
    else if (dpTable[index][capacity] != -1)
        return dpTable[index][capacity];

    if (products[index].weight > capacity) /// Not Take Condition
    {
        /// Skip the current product  = Not Take
        int friend_ = zeroOneKnapsack_BruteForce(products, capacity, index + 1);
        dpTable[index][capacity] = friend_;
        return friend_;
    }
    else
    {
        //
        /// take the current product
        int take = products[index].value;
        int nibo_andFriend = zeroOneKnapsack_BruteForce(products, capacity - products[index].weight, index + 1); // calling friend
        take += nibo_andFriend;

        //
        /// Skip the current product = Not Take
        int notTake = 0;
        int niboNa_andFriend = zeroOneKnapsack_BruteForce(products, capacity, index + 1); // calling friend
        notTake += niboNa_andFriend;

        dpTable[index][capacity] = max(take, notTake);

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

    ans = zeroOneKnapsack_BruteForce(products, bagCapacity, 0); // value in bag
    cout << "Value of the bag: " << ans << nl << nl;

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