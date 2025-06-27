#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

// buy and sell as many times
int f(vector<int> &prices, vector<vector<int>> &dp, int ind, int buy)
{
    if (ind == prices.size())
        return 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    int profit = 0;
    if (buy)
    {
        profit = max(-prices[ind] + f(prices, dp, ind + 1, 0),
                     0 + f(prices, dp, ind + 1, 1));
    }
    else
    {
        profit = max(prices[ind] + f(prices, dp, ind + 1, 1),
                     0 + f(prices, dp, ind + 1, 0));
    }
    return dp[ind][buy] = profit;
}

void solve()
{
    vi prices = {7, 1, 5, 3, 6, 4};
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    cout << "Max Profit: " << f(prices, dp, 0, 1);
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