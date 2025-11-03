#include <bits/stdc++.h>
using namespace std;
#include <chrono>

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

// Memoization
int maxSumOfNonAdjacentElem(vi &arr, int ind, vi &dp){
    if(ind < 0) return 0;
    if(ind == 0) return arr[ind];
    if(dp[ind] != -1) return dp[ind];

    int pick = arr[ind] + maxSumOfNonAdjacentElem(arr, ind-2, dp);
    int notpick = 0 + maxSumOfNonAdjacentElem(arr, ind-1, dp);
    return dp[ind] = max(pick, notpick);
}

// Tabulation
int maxSumOfNonAdjacentElemTabulation(vi &arr, int ind, vi &dp){
    dp[0] = arr[0];
    for(int i=1;i<arr.size();i++){
        int pick = arr[i];
        if(i > 1) pick += dp[i-2];
        int notpick = dp[i-1];
        dp[i] = max(pick, notpick);
    }
    return dp[arr.size() - 1];
}

// Space Optimization
int maxSumOfNonAdjacentElemSpaceOptimization(vi &arr, int ind, vi &dp){
    int prev = arr[0];
    int prev2 = 0;
    for(int i=1;i<arr.size();i++){
        int pick = arr[i];
        if(i > 1) pick += prev2;
        int notpick = prev;
        int curr = max(pick, notpick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

void solve() {
    auto start = chrono::high_resolution_clock::now();

    // Example usage:
    vi arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    vi dp(n, -1);
    int res = maxSumOfNonAdjacentElem(arr, n-1, dp);
    cout << "Result: " << res << endl;
    
    vi dp2(n, -1);
    int res2 = maxSumOfNonAdjacentElemTabulation(arr, n-1, dp2);
    cout << "Result: " << res2 << endl;
    
    vi dp3(n, -1);
    int res3 = maxSumOfNonAdjacentElemSpaceOptimization(arr, n-1, dp3);
    cout << "Result: " << res3 << endl;

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