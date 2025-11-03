#include <bits/stdc++.h>
using namespace std;
#include <chrono>

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

// Recursion
int uniquePaths(int row, int col)
{
    if (row == 0 && col == 0)
        return 1;
    if (row < 0 || col < 0)
        return 0;
    int up = uniquePaths(row - 1, col);
    int left = uniquePaths(row, col - 1);
    return up + left;
}

// Memoization
int uniquePathsMemoization(int row, int col, vvi &dp)
{
    if (row == 0 && col == 0)
        return 1;
    if (row < 0 || col < 0)
        return 0;

    if (dp[row][col] != -1)
        return dp[row][col];

    int up = uniquePathsMemoization(row - 1, col, dp);
    int left = uniquePathsMemoization(row, col - 1, dp);
    return dp[row][col] = up + left;
}

// Tabulation
int uniquePathsTabulation(int row, int col)
{
    vvi dp(row, vi(col, -1));
    dp[0][0] = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0 && j == 0)
                continue;
            int up = 0;
            int left = 0;
            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];
            dp[i][j] = up + left;
        }
    }
    return dp[row - 1][col - 1];
}

// Space Optimization
int uniquePathsSpaceOptimization(int row, int col)
{
    vi prev(col, 0);
    for (int i = 0; i < row; i++)
    {
        vi curr(col, 0);
        for (int j = 0; j < col; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = 1;
            else
            {
                int up = 0;
                int left = 0;
                if(i > 0)
                    up = prev[j];
                if(j > 0)
                    left = curr[j-1];
                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[col-1];
}

void solve()
{
    auto start = chrono::high_resolution_clock::now();

    int row = 3;
    int col = 7;
    vvi dp(row, vi(col, -1));
    cout << "Unique Paths Recursion: " << uniquePaths(row - 1, col - 1) << endl;
    cout << "Unique Paths Memoization: " << uniquePathsMemoization(row - 1, col - 1, dp) << endl;
    cout << "Unique Paths Tabulation: " << uniquePathsTabulation(row, col) << endl;
    cout << "Unique Paths Space Optimization: " << uniquePathsSpaceOptimization(row, col) << endl;

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    cout << "\n\nTime taken: " << duration.count() << " ns\n";
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