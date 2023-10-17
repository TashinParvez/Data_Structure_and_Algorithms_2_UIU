#include <iostream>
using namespace std;

int largestElement(int arr[], int currentIndex)
{
    if (currentIndex == 0)
        return arr[currentIndex];
    else
    {
        int currentValue = arr[currentIndex];
        int friend_ = largestElement(arr, currentIndex - 1);
        return max(currentValue, friend_); 
    }
}

int main()
{
    int arr[10] = {6, 9, 8, 4, 5, 1, 2, 3, 4, 5};
    int n = 10;

    int result = largestElement(arr, n - 1);
    
    cout << result << endl;
    return 0;
}
