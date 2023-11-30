
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

bool compare(Product a, Product b) /// ascending order sort on basis of value/weight
{
    // return (a.value / a.weight) > (b.value / b.weight); /// spmetimes it creat Precision error
    return (a.value * b.weight) > (b.value * a.weight); /// to avoide Precision error
}

double fractionalKnapsack_Greedy(vector<Product> products, int capacity)
{
    double ans = 0;
    for (int i = 0; i < products.size(); i++)
    {
        if (products[i].weight <= capacity)
        {
            cout << products[i].productID << " ";
            ans += products[i].value;
            capacity -= products[i].weight;
        }
        else
        {
            // cout << "Tashin" << nl;
            cout << products[i].productID << " ";
            ans += capacity * ((1.0 * products[i].value) / products[i].weight);
            capacity = 0;
            break;
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
    cin >> bagCapacity; // bag size

    sort(products.begin(), products.end(), compare);
    printSortedProducts(products);
    cout << nl;
    double ans;

    ans = fractionalKnapsack_Greedy(products, bagCapacity); // value in bag
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