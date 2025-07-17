#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

bool allocationIsPossible(int barrier, vi &nums, int students){
    int pages = 0, allocatedStudent = 1;
    int n = nums.size();
    for(int i=0;i<n;i++){
        if(nums[i] > barrier) return false;
        if(pages + nums[i] > barrier){
            allocatedStudent++;
            pages = nums[i];
        }
        else{
            pages = pages + nums[i];
        }
    }
    if(allocatedStudent > students) return false;
    return true;
}

int allocateBooks(vi nums, int students){
    int low = *min_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    int res = -1;
    while(low <= high){
        int mid = (low + high) >> 1;
        if(allocationIsPossible(mid, nums, students)){
            res = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

void solve() {
    vi nums = {12,34,67,90};
    int students = 2;
    cout << allocateBooks(nums, students);
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