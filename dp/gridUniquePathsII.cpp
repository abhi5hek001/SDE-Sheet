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
int uniquePathsII(vvi obstacles, int row, int col)
{
    if (row >= 0 && col >= 0 && obstacles[row][col] == 1)
        return 0;
    if (row == 0 && col == 0)
        return 1;
    if (row < 0 || col < 0)
        return 0;

    int up = uniquePathsII(obstacles, row - 1, col);
    int left = uniquePathsII(obstacles, row, col - 1);
    return up + left;
}

// Memoization
int uniquePathsIIMemoization(vvi obstacles, int row, int col, vvi &dp)
{
    if (row >= 0 && col >= 0 && obstacles[row][col] == 1)
        return 0;
    if (row == 0 && col == 0)
        return 1;
    if (row < 0 || col < 0)
        return 0;

    if (dp[row][col] != -1)
        return dp[row][col];

    int up = uniquePathsIIMemoization(obstacles, row - 1, col, dp);
    int left = uniquePathsIIMemoization(obstacles, row, col - 1, dp);

    return dp[row][col] = up + left;
}

// Tabulation
int uniquePathsIITabulation(vvi obstacles, int row, int col)
{
    vvi dp(row, vi(col, 0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (obstacles[i][j] == 1)
                dp[i][j] = 0;
            else if (i == 0 && j == 0)
                dp[i][j] = 1;
            else {
                int up = 0;
                int left = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[row - 1][col - 1];
}


// Space Optimization
int uniquePathsIISpaceOptimization(vvi obstacles, int row, int col)
{
    vi prev(col, 0);
    for (int i = 0; i < row; i++)
    {
        vi curr(col, 0);
        for (int j = 0; j < col; j++)
        {
            if (obstacles[i][j] == 1)
                curr[j] = 0;
            else if (i == 0 && j == 0)
                curr[j] = 1;
            else {
                int up = 0;
                int left = 0;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = curr[j - 1];
                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[col - 1];
}

void solve()
{
    auto start = chrono::high_resolution_clock::now();

    vvi obstacles = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int row = obstacles.size();
    int col = obstacles[0].size();
    cout << "Unique Paths II Recursion: " << uniquePathsII(obstacles, row - 1, col - 1) << endl;
    vvi dp(row, vi(col, -1));
    cout << "Unique Paths II Memoization: " << uniquePathsIIMemoization(obstacles, row - 1, col - 1, dp) << endl;
    cout << "Unique Paths II Tabulation: " << uniquePathsIITabulation(obstacles, row, col) << endl;
    cout << "Unique Paths II Space Optimization: " << uniquePathsIISpaceOptimization(obstacles, row, col) << endl;

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