#include <iostream>
using namespace std;
struct MinMax
{
    int minimum;
    int maximum;
};

MinMax minMaxElement(int arr[], int currentIndex)
{
    if (currentIndex == 0)
        return {arr[currentIndex], arr[currentIndex]};
    else
    {
        int currentValue = arr[currentIndex];
        MinMax friend_ = minMaxElement(arr, currentIndex - 1);
        MinMax result = friend_; 
        
        if (currentValue < result.minimum)
            result.minimum = currentValue;
        else if (currentValue > result.maximum)
            result.maximum = currentValue;
        return result;
    }
}

int main()
{
    int arr[10] = {6, 9, 8, 4, 5, 1, 2, 3, 4, 5};
    int n = 10;

    MinMax result = minMaxElement(arr, n - 1);

    cout << result.minimum << " " << result.maximum << endl;
    return 0;
}
