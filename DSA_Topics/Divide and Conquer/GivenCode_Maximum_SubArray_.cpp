#include <iostream>
using namespace std;

struct Result
{
    int sum;
    int leftIndex;
    int rightIndex;
};

Result crossingSum(int arr[], int left, int mid, int right)
{
    /// left side of crossing
    int sum = arr[mid];
    int LS = arr[mid];
    int LS_index = mid;
    for (int i = mid - 1; i >= left; i--)
    {
        sum = sum + arr[i];
        if (sum > LS)
        {
            LS = sum;
            LS_index = i;
        }
    }
    /// right side of crossing
    sum = arr[mid + 1];
    int RS = arr[mid + 1];
    int RS_index = mid + 1;
    for (int i = mid + 2; i <= right; i++)
    {
        sum = sum + arr[i];
        if (sum > RS)
        {
            RS = sum;
            RS_index = i;
        }
    }
    /// crossing
    Result CS;
    CS.sum = LS + RS;
    CS.leftIndex = LS_index;
    CS.rightIndex = RS_index;
    return CS;
}

Result maximumSumSubarray(int arr[], int left, int right) // main
{
    if (left == right) /// one element
    {
        Result result;
        result.sum = arr[left];
        result.leftIndex = result.rightIndex = right;

        return result;
    }
    else
    {
        /// int mid = (left+right)/2;
        int mid = left + ((right - left) / 2); 

        Result leftSide = maximumSumSubarray(arr, left, mid);
        Result rightSide = maximumSumSubarray(arr, mid + 1, right);

        Result crossing = crossingSum(arr, left, mid, right);

        if (leftSide.sum >= rightSide.sum && leftSide.sum >= crossing.sum)
            return leftSide;
        else if (rightSide.sum >= leftSide.sum && rightSide.sum >= crossing.sum)
            return rightSide;
        else
            return crossing;
    }
}

int main()
{
    int n = 8;
    int arr[8] = {-2, -5, 6, -2, -3, 1, 5, -6};

    Result result = maximumSumSubarray(arr, 0, n - 1);

    cout << "Summation is: " << result.sum << endl; 
    cout << "Index: " << result.leftIndex << " " << result.rightIndex << endl;
}
