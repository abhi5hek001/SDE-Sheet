#include <bits/stdc++.h>
using namespace std;

void subsetSumII(int n, vector<int> &nums, int ind, vector<int> ds){
    if(ds.empty()) cout << "[]";
    else{
        for(auto it: ds){
            cout << it << " ";
        }
    }
    cout << endl;
    for(int i = ind;i<n;i++){
        // remove duplicate entries
        // if we remove this line then all subsets are found i.e. power set
        if(i!=ind && nums[i]==nums[i-1]) continue;

        ds.push_back(nums[i]);
        subsetSumII(n, nums, i+1, ds);
        ds.pop_back();
    }
}

void solve() {
    vector<int> nums = {1, 2, 2, 2, 3, 3};
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> ds;
    subsetSumII(n, nums, 0, ds);
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