///.................*** بسم الله الرحمن الرحيم ***.................///

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int

void inputArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> A[i];
}

void outputArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            cout << A[i] << " ";
    }
    cout << A[n - 1] << endl;
}

/// Start writing code from here...

void Merge(int *A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1], R[n2 + 1];

    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    L[n1] = 999999;

    for (int i = 0; i < n2; i++)
        R[i] = A[q + 1 + i];
    L[n2] = 999999;

    int i = 0, j = 0, k = p;
    while (k <= r)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
}

void mergeSort(int *A, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}

int main()
{
    int n;
    cin >> n;
    int A[n];
    inputArray(A, n);

    mergeSort(A, 0, n - 1);
    outputArray(A, n);

    return 0;
}

