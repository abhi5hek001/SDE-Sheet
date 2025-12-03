#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

// TC - O(n)
// SC - O(1)
void dutchNationalFlag(vi &nums, int n){
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[mid], nums[low]);
            mid++; low++;
        }
        else if(nums[mid] == 1){
            mid++;
        }
        else if(nums[mid] == 2){
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

void print(vi nums){
    for(auto it: nums)
        cout << it << " ";
    cout << endl;
}

void solve() {
    vi nums = {0,1,1,0,1,2,1,2,0,0,0};
    print(nums);
    int n = nums.size();
    dutchNationalFlag(nums, n);
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