// Given a string s, find the length of the longest substring without repeating characters.

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;
    int maxAns = 0, prev = 0;
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        if (mp.find(s[i]) != mp.end())
        {
            cout << "Character '" << s[i] << "' found at index " << i << ", previous occurrence at index " << mp[s[i]] << endl;
            maxAns = max(maxAns, i - prev);
            prev = max(prev, mp[s[i]] + 1);
            mp[s[i]] = i;
        }
        else
        {
            mp[s[i]] = i;
        }
    }
    cout << "Length of the longest substring without repeating characters: " << maxAns << endl;
}

// Time Complexity: O(n)
// Space Complexity: O(min(n, m)), where n is the length of the string and m is the size of the character set.