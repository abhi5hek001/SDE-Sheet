#include <bits/stdc++.h>
using namespace std;

// TC - O(2^n * k) where t is number of times, k is avg length
// SC - O(k * x) where there are x combinations
void combinationSumII(int ind, int target, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans){
    if(target == 0){
        ans.push_back(ds);
        return;
    }
    for(int i=ind; i<nums.size();i++){
        // not allows duplicate entry
        if(i>ind && nums[i] == nums[i-1]) continue;
        if(nums[i] > target) break;

        ds.push_back(nums[i]);
        combinationSumII(i+1, target-nums[i], nums, ds, ans);
        ds.pop_back();
    }
}

void solve() {
    vector<int> nums = {1, 3, 1, 2, 2, 5, 3, 2, 1};
    sort(nums.begin(), nums.end());
    int target = 5;
    vector<int> ds;
    vector<vector<int>> ans;
    combinationSumII(0, target, nums, ds, ans);
    for(auto it: ans){
        for(auto i: it){
            cout << i << " ";
        }
        cout << endl;
    }
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