#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

int removeDuplicates(vi &nums, int n){
    int i = 0;
    for(int j = 1;j < n; j++){
        if(nums[j] != nums[i]){
            nums[i+1] = nums[j];
            i++;
        }
    }
    return i+1;
}

void print(vi &nums){
    for(auto it: nums)
        cout << it << " ";
    cout << endl;
}

void solve() {
    vi nums = {1,1,2,3,4,5,5,8,8,9,9,9};
    print(nums);
    cout << removeDuplicates(nums, nums.size()) << endl;
    print(nums);
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