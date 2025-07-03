#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

int subarraySumWithXORk(vi nums, int k){
    int xr = 0;
    unordered_map<int, int> mp;
    // important
    mp[0] = 1;
    int n = nums.size();
    int cnt = 0;
    for(int i=0;i<n;i++){
        xr = xr ^ nums[i];
        int num = xr^k;
        if(mp.find(num) == mp.end()){
            mp[xr]++;
        }else{
            cnt += mp[num];
        }
    }
    return cnt;
}

void solve() {
    vi nums = {4,2,2,6,4};
    int k = 6;
    cout << subarraySumWithXORk(nums, k) << endl;
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