#include <bits/stdc++.h>
using namespace std;
#include <chrono>

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

// Recursion
int findMaxCherriesCollected(vvi &grid, int row, int col, int i, int j1, int j2){
    // out of bound
    if(j1 < 0 || j1 >= col || j2 < 0 || j2 >= col) 
        return INT_MIN/2;
    // base case
    if(i == row-1){
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }
    vi dj = {-1, 0, 1};
    int maxi = INT_MIN/2;
    for(int dj1 = -1;dj1 <= 1; dj1++){
        for(int dj2 = -1;dj2 <= 1; dj2++){
            if(j1 == j2){
                maxi = max(maxi, grid[i][j1] + findMaxCherriesCollected(grid,row,col,i+1,(j1+dj1),(j2+dj2)));
            } 
            else{
                maxi = max(maxi, grid[i][j1] + grid[i][j2] + findMaxCherriesCollected(grid,row,col,i+1,(j1+dj1),j2+dj2));
            }
        }
    }
    return maxi;
}

// Memoization
int findMaxCherriesCollectedMemoization(vvi &grid, int row, int col, int i, int j1, int j2, vvvi &dp){
    // out of bound
    if(j1 < 0 || j1 >= col || j2 < 0 || j2 >= col) 
        return INT_MIN/2;
    // base case
    if(i == row-1){
        if(j1 == j2) dp[i][j1][j2] = grid[i][j1];
        else dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
    }

    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    vi dj = {-1, 0, 1};
    int maxi = INT_MIN/2;
    for(int dj1 = -1;dj1 <= 1; dj1++){ 
        for(int dj2 = -1;dj2 <= 1; dj2++){
            int value = 0;
            if(j1 == j2)
                value = grid[i][j1];
            else
                value = (grid[i][j1] + grid[i][j2]);
            
            value += findMaxCherriesCollectedMemoization(grid,row,col,i+1,(j1+dj1),(j2+dj2), dp);
            maxi = max(value, maxi);
        }
    }
    return dp[i][j1][j2] = maxi;

}

void solve() {
    auto start = chrono::high_resolution_clock::now();

    vvi grid = {
        {3,1,1},
        {2,5,1},
        {1,5,5},
        {2,1,1}
    };
    int row = grid.size();
    int col = grid[0].size();
    cout << "Maximum Cherries Collected Recursion: " << findMaxCherriesCollected(grid, row, col, 0, 0, col-1) << endl;
    vvvi dp(row, vvi(col, vi(col, -1)));
    cout << "Maximum Cherries Collected Memoization: " << findMaxCherriesCollectedMemoization(grid, row, col, 0, 0, col-1,dp) << endl;

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    cout << "\n\nTime taken: " << duration.count() << " ns\n";
}

signed main() {
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}