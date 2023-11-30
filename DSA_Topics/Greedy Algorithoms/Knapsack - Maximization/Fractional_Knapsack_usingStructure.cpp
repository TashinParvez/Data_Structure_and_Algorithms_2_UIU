
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

bool compare(Product a, Product b) /// decending order sort on basis of value/weight
{
    // return (a.value / a.weight) > (b.value / b.weight); /// sometimes it creat Precision error

    return (a.value * b.weight) > (b.value * a.weight); /// to avoide Precision error
}

double fractionalKnapsack_Greedy(vector<Product> products, int capacity)
{
    double ans = 0;
    for (int i = 0; i < products.size(); i++)
    {
        if (products[i].weight <= capacity)
        {
            cout << products[i].productID << " "; /// picked product

            ans += products[i].value;
            capacity -= products[i].weight;
        }
        else
        {
            cout << products[i].productID << " "; /// picked product

            ans += capacity * ((1.0 * products[i].value) / products[i].weight);
            capacity = 0;
            break; /// capacity is zero so I can't anything more
        }
    }

    return ans;
}

void printSortedProducts(vector<Product> products)
{
    cout << nl << "Sorted Products : ";
    for (Product p : products)
    {
        cout << p.productID << " ";
    }
    cout << nl;
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
    cin >> bagCapacity; ///---->      bag/Knapsack size

    sort(products.begin(), products.end(), compare); /// Sorting based on ther Value / weight

    printSortedProducts(products);
    cout << nl;

    double ans = fractionalKnapsack_Greedy(products, bagCapacity); // value in bag
    cout << "Value of the bag: " << ans << nl << nl;

    CRACKED;
}

/*--------->      Test Case 1

4

p1 1 1
p2 4 3
p3 5 4
p4 7 5

7


*/

/*--------->      Test Case 2


5

P1 21 7
P2 24 4
P3 12 6
P4 40 5
P5 30 6

20


*/