#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

int longestSubstringWithoutRepeat(string s)
{
    // position map
    // vector<int> mpp(256, -1);
    // int left = 0, right = 0;
    // int n = s.size();
    // int len = 0;
    // while (right < n)
    // {
    //     if (mpp[s[right]] != -1)
    //     {
    //         left = max(mpp[s[right]] + 1, left);
    //     
    //     mpp[s[right]] = right;

    //     len = max(len, right - left + 1);
    //     right++;
    // }
    // return len;

    // unordered_map
    int left = 0, right = 0;
    unordered_map<char, int> mp;
    int maxLen = 0;
    int n = s.size();
    while (right < n)
    {
        if (mp.find(s[right]) != mp.end())
        {
            // to ensure only forward left pointer movement
            left = max(left, mp[s[right]] + 1);
        }
        mp[s[right]] = right;

        maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;
}

void solve()
{
    string s = "abcaabcdba";
    cout << longestSubstringWithoutRepeat(s) << endl;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}