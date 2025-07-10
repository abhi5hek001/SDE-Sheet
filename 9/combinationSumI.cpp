#include <bits/stdc++.h>
using namespace std;

// TC - O(2^t * k) where t is number of times, k is avg length
// SC - O(k * x) where there are x combinations
void combinationSum(int ind, int target, vector<int> &nums, vector<int> &ds){
    if(ind == nums.size()) {
        if(target == 0){
            for(auto it: ds){
                cout << it << " ";
            }   
            cout << endl;
        }
        return;
    }
    
    if(nums[ind] <= target){
        ds.push_back(nums[ind]);
        // pick the element
        combinationSum(ind, target-nums[ind], nums, ds);
        // In backtracking, popping back the element before not picking it
        ds.pop_back();
    }
    // not pick the element
    combinationSum(ind+1, target, nums, ds);
}

void solve() {
    vector<int> nums = {2, 3, 6, 7};
    int target = 7;
    vector<int> ds;
    combinationSum(0, target, nums, ds);
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