#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

int countPaths(int i, int j, int n, int m)
{
    // reached ending point
    if (i == n - 1 && j == m - 1)
        return 1;
    // out of range
    if (i >= n || j >= m)
        return 0;
    return countPaths(i + 1, j, n, m) + countPaths(i, j + 1, n, m);
}

int countPathsBetter(int i, int j, int n, int m, vvi &dp)
{
    // reached ending point
    if (i == n - 1 && j == m - 1)
        return 1;
    // out of range
    if (i >= n || j >= m)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    else
        return dp[i][j] = countPathsBetter(i + 1, j, n, m, dp) + countPathsBetter(i, j + 1, n, m, dp);
}

int countPathsOptimal(int i, int j, int n, int m)
{
    int N = (m+n-2);
    int r = m-1;
    double res = 1;
    for(int i=1;i<=r;i++){
        res = res * (N-r+i) / i;
    }
    return (int) res;
}

void solve()
{
    int n = 2;
    int m = 3;
    cout << "Brute" << endl;
    cout << countPaths(0, 0, n, m) << endl;
    cout << "Better" << endl;
    vvi dp(n, vi(m, -1));
    cout << countPathsBetter(0, 0, n, m, dp) << endl;
    cout << "Optimal" << endl;
    cout << countPathsOptimal(0, 0, n, m) << endl;
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