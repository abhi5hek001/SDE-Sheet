#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

int searchElemInRotatedSortedArray(vi nums, int n, int target){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = (low + high) >> 1;
        if(nums[mid] == target) return mid;
        else if(nums[low] <= target && target <= nums[mid]){
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return (low > high) ? -1 : low;
}

void solve() {
    vi nums = {4,5,6,7,0,1,2};
    int n = nums.size();
    int target = 0;
    cout << searchElemInRotatedSortedArray(nums, n, target);
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