#include <iostream>
using namespace std;

bool isPalindrome(string str, int left, int right)
{
    if (left >= right)
        return true;
    else
    {
        if (str[left] == str[right])
        {
            bool friend_ = isPalindrome(str, left + 1, right - 1);
            return friend_;
        }
        else
            return false;
    }
}

int main()
{
    string str = "madam";
    bool result = isPalindrome(str, 0, str.size() - 1);
    if (result == true)
        cout << "Palindrome\n";
    else
        cout << "Not a Palindrome\n";
    return 0;
}