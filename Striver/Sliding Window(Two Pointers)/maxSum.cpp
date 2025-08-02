// Given an array of intergers and an integer k, you have to select k numbers in total at a point you can select
// either the leftmost number or the rightmost number from the array.
// You have to maximize the sum of the selected numbers.

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cout << "Enter the number of elements to select (k): ";
    cin >> k;

    int curSum = 0, maxSum = 0;

    for (int i = 0; i < k; i++)
    {
        curSum += arr[i];
    }
    maxSum = curSum;

    for (int i = 0; i < k; i++)
    {
        // cout << "Current sum after selecting " << i + 1 << " elements: " << curSum << endl;
        curSum = curSum - arr[k - 1 - i] + arr[n - 1 - i];
        maxSum = max(maxSum, curSum);
    }

    cout << "The maximum sum of " << k << " elements is: " << maxSum << endl;

    return 0;
}

// Time complexity: O(2*k)
// Space complexity: O(1)