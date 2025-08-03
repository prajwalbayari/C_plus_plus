// Given an array of elements containing 0s and 1s, find the maximum number of consecutive 1s in the array.
// You are allowed to flip atmost k 0s

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int optimizedAns(int k, vector<int> &vec)
{
    int l = 0, r = 0, maxAns = 0, zeros = 0;
    while (r < vec.size())
    {
        zeros = zeros + !vec[r];
        if (zeros > k)
        {
            zeros = zeros - !vec[l];
            l++;
        }
        if (zeros <= k)
            maxAns = max(maxAns, r - l + 1);
        r++;
    }
    return maxAns;
}

int main()
{
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> vec(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    cout << "Enter the value of k: ";
    cin >> k;

    int maxAns = 0, left = 0, right = 0, cnt = 0;
    while (left < n && right < n)
    {
        if (vec[right] == 0)
            cnt++;
        while (cnt > k && left <= right)
        {
            if (vec[left++] == 0)
                cnt--;
        }
        maxAns = max(maxAns, right - left + 1);
        right++;
    }

    cout << "Maximum number of consecutive one's available with " << k << " flips allowed is: " << maxAns << endl;
    cout << "Maximum number of consecutive one's available with " << k << " flips allowed is: " << optimizedAns(k, vec) << endl;

    return 0;
}

// Time complexity:O(2*n)
// Space complexity:O(1)

// Optimized approach:
//  Time complexity:O(n)
//  Space complexity:O(1)