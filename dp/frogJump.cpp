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
// int frogJump(int ind, vi &arr, vi &dp){
//     if(ind == 0) return 0;
    
//     if(dp[ind] != -1) return dp[ind];

//     int step1 = frogJump(ind-1, arr, dp) + abs(arr[ind] - arr[ind-1]);
//     int step2 = INT_MAX;
//     if(ind > 1){
//         step2 = frogJump(ind-2, arr, dp) + abs(arr[ind] - arr[ind-2]);
//     }

//     return dp[ind] = min(step1, step2);
// }

// Tabulation
// int frogJump(int ind, vi &arr, vi &dp){
//     dp[0] = 0;
//     for(int i=1;i<arr.size();i++){
//         int step1 = dp[i-1] + abs(arr[i] - arr[i-1]);
//         int step2 = INT_MAX;
//         if(i > 1){
//             step2 = dp[i-2] + abs(arr[i] - arr[i-2]);
//         }
//         dp[i] = min(step1, step2);
//     }
//     return dp[arr.size()-1];
// }

// Space Optimization
int frogJump(int ind, vi &arr, vi &dp){

    int prev2 = 0;
    int prev = abs(arr[1] - arr[0]);

    for(int i=2;i<arr.size();i++){
        int step1 = prev + abs(arr[i] - arr[i-1]);
        int step2 = INT_MAX;
        if(i > 1){
            step2 = prev2 + abs(arr[i] - arr[i-2]);
        }
        int curr = min(step1, step2);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

void solve() {
    auto start = chrono::high_resolution_clock::now();

    vi arr = {0,1,3,5,6,8,12,17};
    int n = arr.size();
    vi dp(n+1, -1);
    int res = frogJump(n-1, arr, dp);
    cout << "Result: " << res << endl;

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