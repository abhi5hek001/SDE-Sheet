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
int findMinPathSumTriangle(vvi &triangle, int i, int j, int row, int col){
    if(i == row-1) return triangle[i][j];

    int down = triangle[i][j] + findMinPathSumTriangle(triangle, i+1, j, row, col);
    int diagonal = triangle[i][j] + findMinPathSumTriangle(triangle, i+1, j+1, row, col);

    return min(down, diagonal);
}

// Memoization
int findMinPathSumTriangleMemoization(vvi &triangle, int i, int j, int row, int col, vvi &dp){
    if(i == row-1) return triangle[i][j];

    if(dp[i][j] != -1) return dp[i][j];

    int down = triangle[i][j] + findMinPathSumTriangleMemoization(triangle, i+1, j, row, col, dp);
    int diagonal = triangle[i][j] + findMinPathSumTriangleMemoization(triangle, i+1, j+1, row, col, dp);

    return dp[i][j] = min(down, diagonal);
}

// Tabulation
int findMinPathSumTriangleTabulation(vvi &triangle, int row, int col){
    vvi dp(row);
    for(int i=0;i<row;i++){
        dp[i] = vi(triangle[i].size(), -1);
    }
    for(int j =0;j<triangle[row-1].size();j++){
        dp[row-1][j] = triangle[row-1][j];
    }
    for(int i=row-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int down = triangle[i][j] + dp[i+1][j];
            int diagonal = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down, diagonal);
        }
    }
    return dp[0][0];
}

// Space Optimization
int findMinPathSumTriangleSpaceOptimization(vvi &triangle, int row, int col){
    vi front(row, -1);
    for(int j =0;j<triangle[row-1].size();j++){
        front[j] = triangle[row-1][j];
    }
    for(int i=row-2;i>=0;i--){
        vi curr(row, -1);
        for(int j=i;j>=0;j--){
            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j+1];
            curr[j] = min(down, diagonal);
        }
        front = curr;
    }
    return front[0];
}

void solve()
{
    auto start = chrono::high_resolution_clock::now();

    // Example usage:
    vvi triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};
    int row = triangle.size();
    int col = triangle[0].size();
    cout << "Minimum Path Sum Triangle Recursion: " << findMinPathSumTriangle(triangle, 0, 0, row, col) << endl;
    vvi dp(row);
    for(int i=0;i<row;i++){
        dp[i] = vi(triangle[i].size(), -1);
    }
    cout << "Minimum Path Sum Triangle Memoization: " << findMinPathSumTriangleMemoization(triangle, 0, 0, row, col, dp) << endl;
    cout << "Minimum Path Sum Triangle Tabulation: " << findMinPathSumTriangleTabulation(triangle, row, col) << endl;
    cout << "Minimum Path Sum Triangle Space Optimization: " << findMinPathSumTriangleSpaceOptimization(triangle, row, col) << endl;

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