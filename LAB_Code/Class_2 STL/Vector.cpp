#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comparator(int a, int b)
{
    if (a >= b)
        return true;
    else
        return false;
}

int main()
{

    vector<int> myVector;

    /// insert Last
    myVector.push_back(10);
    myVector.push_back(15);
    myVector.push_back(12);
    myVector.push_back(17);
    myVector.push_back(22);
    myVector.push_back(5);
    myVector.push_back(8);
    myVector.push_back(2);
    myVector.push_back(150);

    /// size of the vector
    int SIZE = myVector.size();

    /// printing the vector
    for (int i = 0; i < SIZE; i++)
        cout << myVector[i] << " ";
    cout << endl;

    /// sorting the vector

    // sort(myVector.begin(), myVector.begin() + 3); // sort only first 3 elements

    // for (int i = 0; i < SIZE; i++) // printing the vector
    //     cout << myVector[i] << " ";
    // cout << endl;

    /// sort(myVector.begin(), myVector.end()); // ascending order sort

    // for (int i = 0; i < SIZE; i++)       // printing the vector
    //     cout << myVector[i] << " ";
    // cout << endl;

    sort(myVector.begin(), myVector.end(), comparator); // decending order

    /// printing the vector
    for (int i = 0; i < SIZE; i++)
        cout << myVector[i] << " ";
    cout << endl;

    return 0;
}