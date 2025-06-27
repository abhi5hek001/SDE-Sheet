#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

int findDuplicateElement(vi nums, int n){
    int slow = nums[0];
    int fast = nums[0];
    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while(slow != fast);

    fast = nums[0];
    while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return fast;
}

void solve() {
    vi nums = {2,5,9,6,9,3,8,9,7,1};
    int n = nums.size();
    for(auto it: nums){
        cout << it << " ";
    }
    cout << endl;
    cout << "Duplicate element is: " << findDuplicateElement(nums, n) << endl;
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