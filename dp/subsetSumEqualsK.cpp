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
bool subsetSumToK(int ind, int n, int target, vector<int> &arr) {
    if(target == 0) return true;
    if(ind == arr.size()) return false;

    bool take = false;
    if(arr[ind] <= target)
        take = subsetSumToK(ind+1, n, target - arr[ind], arr);
    
    bool nottake = subsetSumToK(ind+1, n, target, arr);
    return (take || nottake);
}

// Memoization
bool subsetSumToKMemoization(int ind, int n, int target, vector<int> &arr, vector<vector<bool>> &dp) {
    if(target == 0) return true;
    if(ind == arr.size()) return false;

    if(dp[n][target] == -1) return dp[n][target];

    bool take = false;
    if(arr[ind] <= target)
        take = subsetSumToKMemoization(ind+1, n, target - arr[ind], arr, dp);
    
    bool nottake = subsetSumToKMemoization(ind+1, n, target, arr, dp);
    return dp[n][target] = (take || nottake);
}

// Tabulation
bool subsetSumToKTabulation(int ind, int n, int target, vector<int> &arr) {

    vector<vector<bool>> dp(1e3, vector<bool>(1e3, false));

    for(int i = 0;i<n;i++){
        dp[i][0] = true;
    }
    if(arr[n-1] <= target)
        dp[n-1][arr[n-1]] = true;

    for(int i=n-2;i>=0;i--){
        for(int j=1;j<=target;j++){
            bool notTake = dp[i+1][j];

            bool take = false;
            if(arr[i] <= j)
                take = dp[i+1][j-arr[i]];
            
            dp[i][j] = take || notTake;
        }
    }
    return dp[0][target];
}

// Space Optimization
bool subsetSumToKSpaceOptimization(int ind, int n, int target, vector<int> &arr) {

    vector<bool> prev(target+1, false), curr(target+1, false);

    prev[0] = true;

    if(arr[0] <= target)
        prev[arr[0]] = true;

    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            bool notTake = prev[j];

            bool take = false;
            if(arr[i] <= j)
                take = prev[j-arr[i]];
            
            curr[j] = take || notTake;
        }
        prev = curr;
    }
    return prev[target];
}

void solve() {
    auto start = chrono::high_resolution_clock::now();

    // Example usage:
    vi arr = {1, 2, 3, 4};
    int n = arr.size();
    int k = 4;
    cout << "Result Recursion: " << (subsetSumToK(0, n, k, arr) ? "true" : "false") << endl;
    vector<vector<bool>> dp(1e3, vector<bool>(1e3, false));
    cout << "Result Memoization: " << (subsetSumToKMemoization(0, n, k, arr, dp) ? "true" : "false") << endl;
    cout << "Result Tabulation: " << (subsetSumToKTabulation(n-1, n, k, arr) ? "true" : "false") << endl;
    cout << "Result Space Optimization: " << (subsetSumToKSpaceOptimization(0, n, k, arr) ? "true" : "false") << endl;

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