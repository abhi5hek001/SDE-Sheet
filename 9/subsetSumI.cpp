#include <bits/stdc++.h>
using namespace std;

void subsetSum(vector<int> &nums, int n, int ind, int sum, vector<int> &ans){
    if(ind == n){
        ans.push_back(sum);
        return;
    }
    // not pick the element
    subsetSum(nums, n, ind+1, sum, ans);
    // pick the element
    subsetSum(nums, n, ind+1, sum+nums[ind], ans);
}

void solve() {
    vector<int> nums = {3, 1, 2 };
    int n = nums.size();
    int sum = 0;
    vector<int> ans;
    subsetSum(nums, n, 0, sum, ans);
    for(auto it: ans){
        cout << it << " ";
    }
    cout << endl;
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