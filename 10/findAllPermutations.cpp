#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

void swapNumbers(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void findAllPermutations(vi &nums, int n, int ind){
    if(ind == n){
        for(auto it: nums)
            cout << it << " ";
        cout << endl;
    return;
    }
    for(int i=ind;i<n;i++){
        swapNumbers(nums[ind], nums[i]);
        findAllPermutations(nums, n, ind+1);
        swapNumbers(nums[ind], nums[i]);
    }
}

void solve() {
    vi nums = {1,2,3};
    int n = nums.size();
    findAllPermutations(nums, n, 0);
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