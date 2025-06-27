#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

// buy and sell one time
int maxProfit(vi nums, int n){
    int profit  = 0;
    int mini = nums[0];
    for(int i=1;i<n;i++){
        int cost = nums[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, nums[i]);
    }
    return profit;
}

void solve() {
    vi nums = {7,1,5,3,6,4};
    cout << "Max Profit: " << maxProfit(nums, nums.size());
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