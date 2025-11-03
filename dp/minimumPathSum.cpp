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
int minimumPathSum(vvi &arr, int row, int col)
{
    if (row == 0 && col == 0)
        return arr[row][col];
    if (row < 0 || col < 0)
        return INT_MAX;
    int up = INT_MAX;
    int left = INT_MAX;
    if (row > 0)
        up = arr[row][col] + minimumPathSum(arr, row - 1, col);
    if (col > 0)
        left = arr[row][col] + minimumPathSum(arr, row, col - 1);
    return min(up, left);
}

// Memoization
int minimumPathSumMemoization(vvi &arr, int row, int col, vvi &dp)
{
    if (row == 0 && col == 0)
        return arr[row][col];
    if (row < 0 || col < 0)
        return INT_MAX;

    if (dp[row][col] != -1)
        return dp[row][col];

    int up = INT_MAX;
    int left = INT_MAX;
    if (row > 0)
        up = arr[row][col] + minimumPathSumMemoization(arr, row - 1, col, dp);
    if (col > 0)
        left = arr[row][col] + minimumPathSumMemoization(arr, row, col - 1, dp);
    return dp[row][col] = min(up, left);
}

// Tabulation
int minimumPathSumTabulation(vvi &arr, int row, int col)
{
    vvi dp(row, vi(col, INT_MAX));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = arr[i][j];
            else if (i < 0 || j < 0)
                dp[i][j] = INT_MAX;
            else
            {
                int up = INT_MAX;
                int left = INT_MAX;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = arr[i][j] + min(up, left);
            }
        }
    }
    return dp[row - 1][col - 1];
}


// Space Optimization
int minimumPathSumSpaceOptimization(vvi &arr, int row, int col)
{
    vi prev(col, -1);
    for (int i = 0; i < row; i++)
    {
        vi curr(col, -1);
        for (int j = 0; j < col; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = arr[i][j];
            else
            {
                int up = INT_MAX;
                int left = INT_MAX;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = curr[j - 1];
                curr[j] = arr[i][j] + min(up, left);
            }
        }
        prev = curr;
    }
    return prev[col - 1];
}

void solve()
{
    auto start = chrono::high_resolution_clock::now();

    vvi arr = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};
    int row = arr.size();
    int col = arr[0].size();
    cout << "Minimum Path Sum from Recursion: " << minimumPathSum(arr, row - 1, col - 1) << endl;
    vvi dp(row, vi(col, -1));
    cout << "Minimum Path Sum from Memoization: " << minimumPathSumMemoization(arr, row - 1, col - 1, dp) << endl;
    cout << "Minimum Path Sum from Tabulation: " << minimumPathSumTabulation(arr, row, col) << endl;
    cout << "Minimum Path Sum from Space Optimization: " << minimumPathSumSpaceOptimization(arr, row, col) << endl;

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