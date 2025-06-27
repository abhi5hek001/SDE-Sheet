#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

pii kadaneAlgo(vi nums, int n){
    int sum = 0;
    int maxi = INT_MIN;
    int start = 0;
    int ansStart = 0; int ansEnd = 0;
    for(int i=0;i<n;i++){
        // 
        if(sum == 0) start = i;
        // 
        sum += nums[i];

        if(sum > maxi){
            maxi = max(maxi, sum);
            //    
            ansStart = start;
            ansEnd = i;
            // 
        }

        if(sum < 0) sum = 0;
    }
    return {ansStart, ansEnd};
}

void print(vi &nums, int i, int j){
    for(int it=i;it<=j;it++)
        cout << nums[it] << " ";
    cout << endl;
}

void solve() {
    // maximum subarray sum - contagious part of the array
    vi nums = {-2,-3,4,-1,-2,1,5,-3};
    int n = nums.size();
    pii indices = kadaneAlgo(nums, n);
    print(nums, indices.first, indices.second);
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