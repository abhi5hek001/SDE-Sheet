#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

int longestConsecutiveSequenceBetter(vi nums, int n){
    sort(nums.begin(), nums.end());
    int cnt = 0, lastSmallest = INT_MIN, longest = 1;
    for(int i=0;i<n;i++){
        if(nums[i]-1 == lastSmallest){
            cnt += 1;
            lastSmallest = nums[i];
        }else if(nums[i] != lastSmallest){
            cnt = 1;
            lastSmallest = nums[i];
        }
        longest = max(cnt, longest);
    }
    return longest;
}

int longestConsecutiveSequenceOptimal(vi nums, int n){
    unordered_set<int> st;
    if(n == 0) return 0;
    int longest = 1;
    for(int i=0;i<n;i++){
        st.insert(nums[i]);
    }

    for(auto it: st){
        if(st.find(it - 1) == st.end()){
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st.end()){
                cnt += 1;
                x += 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

void solve() {
    vi nums = {102,4,100,1,101,3,2,1,1};
    cout << longestConsecutiveSequenceBetter(nums, nums.size()) << endl;
    cout << longestConsecutiveSequenceOptimal(nums, nums.size()) << endl;
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