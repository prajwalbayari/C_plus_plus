// Given a string s and an integer k.Find the length of the longest substring with at most k distinct characters.

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int optimized(string &str, int k)
{
    int n = str.size(), l = 0, r = 0, ans = 0;
    unordered_map<char, int> mp;
    while (r < n)
    {
        mp[str[r]]++;
        if (mp.size() > k)
        {
            mp[str[l]]--;
            if (mp[str[l]] == 0)
                mp.erase(str[l]);
            l++;
        }
        if (mp.size() <= k)
            ans = max(ans, r - l + 1);
        r++;
    }
    return ans;
}

int main()
{
    string str;
    cout << "Enter the string: ";
    cin >> str;
    cout << "Enter the value of k: ";
    int k;
    cin >> k;

    unordered_map<char, int> mp;
    int left = 0, right = 0, ans = 0;
    while (right < str.size())
    {
        mp[str[right]]++;
        while (mp.size() > k)
        {
            mp[str[left]]--;
            if (mp[str[left]] == 0)
                mp.erase(str[left]);
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }

    cout << "The maximum answer is: " << ans << endl;
    cout << "(Optimized)The maximum answer is: " << optimized(str, k) << endl;
}

// Time complexity : O(n+n)
// Space complexity : O(k)

// Optimized
// Time complexity : O(n+n)
// Space complexity : O(k)
