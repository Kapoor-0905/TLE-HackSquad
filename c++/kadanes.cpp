// Problem Statement
// Given an array arr[] of size N. The task is to find the sum of the contiguous subarray within a arr[] with the largest sum.

// Solution
//  The idea of Kadane’s algorithm is to maintain a variable max_ending_here that stores the maximum sum contiguous subarray ending at current index and a variable max_so_far stores the maximum sum of contiguous subarray found so far, Everytime there is a positive-sum value in max_ending_here compare it with max_so_far and update max_so_far if it is greater than max_so_far.

#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int size)
{
    // Initialize the variables max_so_far = INT_MIN and max_ending_here = 0
    int max_so_far = INT_MIN, max_ending_here = 0;

    // Run a for loop form 0 to N-1 and for each index i:
    for (int i = 0; i < size; i++)
    {
        // Add the arr[i] to max_ending_here.
        max_ending_here = max_ending_here + a[i];
        // If  max_so_far is less than max_ending_here then update max_so_far  to max_ending_here.
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        // If max_ending_here < 0 then update max_ending_here = 0

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}

// Time Complexity : O(N)
// Auxiliary Space : O(1)