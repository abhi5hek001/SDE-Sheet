#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

int kthLargestElement(vi nums, int n, int k){
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(auto it: nums){
        minHeap.push(it);
        if(minHeap.size() > k){
            minHeap.pop();
        }
    }
    return minHeap.top();
}

void solve() {
    vi nums = {3,2,1,5,6,4};
    int k = 2;
    cout << kthLargestElement(nums, nums.size(), k);
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