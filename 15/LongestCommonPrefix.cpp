#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    // IMPORTANT
    sort(strs.begin(),strs.end());
    int n = strs.size();
    int i = 0;
    while(strs[0].length() > i && strs[n-1].length() > i){
        if(strs[0][i] == strs[n-1][i]){
            i++;
        }
        else{
            return strs[0].substr(0,i);
        }
    }
    return "";
    }

void solve() {
    
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