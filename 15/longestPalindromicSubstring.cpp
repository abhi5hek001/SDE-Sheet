#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

int dp[1001][1001];
bool solve(string &s, int i, int j)
{
    if (i >= j)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == s[j])
        return dp[i][j] = solve(s, i + 1, j - 1);

    return dp[i][j] = 0;
}

string longestPalindrome(string s)
{
    int n = s.length();
    memset(dp, -1, sizeof(dp));

    int maxLen = INT_MIN;
    int sp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {

            if (solve(s, i, j))
            {
                if ((j - i + 1) > maxLen)
                {
                    maxLen = j - i + 1;
                    sp = i;
                }
            }
        }
    }
    return s.substr(sp, maxLen);
}

void solve()
{
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