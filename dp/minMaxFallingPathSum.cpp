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
int findMaxFallingPathSum(vvi &matrix, int i, int j, int col)
{
    if (j < 0 || j >= col)
        return INT_MIN / 2;
    if (i == 0)
        return matrix[i][j];

    int up = matrix[i][j] + findMaxFallingPathSum(matrix, i - 1, j, col);
    int ld = matrix[i][j] + findMaxFallingPathSum(matrix, i - 1, j - 1, col);
    int rd = matrix[i][j] + findMaxFallingPathSum(matrix, i - 1, j + 1, col);

    return max(up, max(ld, rd));
}

// Memoization
int findMaxFallingPathSumMemoization(vvi &matrix, int i, int j, int col, vvi &dp)
{
    if (j < 0 || j >= col)
        return INT_MIN / 2;
    if (i == 0)
        return matrix[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = matrix[i][j] + findMaxFallingPathSum(matrix, i - 1, j, col);
    int ld = matrix[i][j] + findMaxFallingPathSum(matrix, i - 1, j - 1, col);
    int rd = matrix[i][j] + findMaxFallingPathSum(matrix, i - 1, j + 1, col);

    return dp[i][j] = max(up, max(ld, rd));
}

// Tabulation
int findMaxFallingPathSumTabulation(vvi &matrix, int row, int col){
    vvi dp(row, vi(col, -1));

    for(int c = 0;c<col;c++){
        dp[0][c] = matrix[0][c];
    }

    for(int i = 1;i<row;i++){
        for(int j = 0;j<col;j++){
            int d = INT_MIN / 2;
            int ld = INT_MIN / 2;
            int rd = INT_MIN / 2;
            d = matrix[i][j] + dp[i-1][j];
            if(i > 0 && j > 0) ld = matrix[i][j] + dp[i-1][j-1];
            if(i > 0 && j+1 < col) rd = matrix[i][j] + dp[i-1][j+1];
            dp[i][j] = max(d, max(ld, rd));
        }
    }

    int maxi = INT_MIN;
    for(int c = 0;c<col;c++){
        maxi = max(maxi, dp[row-1][c]);
    }
    return maxi;
}

// Space Optimization
int findMaxFallingPathSumSpaceOptimization(vvi &matrix, int row, int col){
    vi prev(col, -1);
    
    for(int c = 0;c<col;c++){
        prev[c] = matrix[0][c];
    }

    for(int i = 1;i<row;i++){
        vi curr(col, -1);
        for(int j = 0;j<col;j++){
            int d = INT_MIN / 2;
            int ld = INT_MIN / 2;
            int rd = INT_MIN / 2;
            d = matrix[i][j] + prev[j];
            if(i > 0 && j > 0) ld = matrix[i][j] + prev[j-1];
            if(i > 0 && j+1 < col) rd = matrix[i][j] + prev[j+1];
            curr[j] = max(d, max(ld, rd));
        }
        prev = curr;
    }

    int maxi = INT_MIN;
    for(int c = 0;c<col;c++){
        maxi = max(maxi, prev[c]);
    }
    return maxi;
}

void solve()
{
    auto start = chrono::high_resolution_clock::now();

    vvi matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}};
    int row = matrix.size();
    int col = matrix[0].size();
    int maxi = INT_MIN;
    for (int c = 0; c < col; c++)
    {
        maxi = max(maxi, findMaxFallingPathSum(matrix, row - 1, c, col));
    }
    cout << "Max Falling Path Sum Recursion: " << maxi << endl;

    maxi = INT_MIN;
    vvi dp(row, vi(col, -1));
    for (int c = 0; c < col; c++)
    {
        maxi = max(maxi, findMaxFallingPathSumMemoization(matrix, row - 1, c, col, dp));
    }
    cout << "Max Falling Path Sum Memoization: " << maxi << endl;

    cout << "Max Falling Path Sum Tabulation: " << findMaxFallingPathSumTabulation(matrix, row, col) << endl;
    cout << "Max Falling Path Sum Space Optimization: " << findMaxFallingPathSumSpaceOptimization(matrix, row, col) << endl;

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