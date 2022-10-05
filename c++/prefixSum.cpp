// Given an array arr[] of size n, its prefix sum array is another array prefixSum[] of the same size, such that the value of prefixSum[i] is arr[0] + arr[1] + arr[2] … arr[i].

#include <bits/stdc++.h>
using namespace std;

// Fills prefix sum array
void fillPrefixSum(int arr[], int n, int prefixSum[])
{
    prefixSum[0] = arr[0];
    // Adding present element with previous element
    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i];
}

// Driver Code
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int prefixSum[n];
    fillPrefixSum(a, n, prefixSum);
    for (int i = 0; i < n; i++)
        cout << prefixSum[i] << " ";
}

// This code is contributed by Aditya Kumar (adityakumar129)
