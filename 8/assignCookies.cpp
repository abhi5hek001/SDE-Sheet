#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

int assignCookies(vi &g, vi &s){
    int n = g.size();
    int m = s.size();
    int child = 0, cookies = 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    while(child < n && cookies < m){
        if(g[child] <= s[cookies]){
            child += 1;
        }
        cookies += 1;
    }
    return child;
}

void solve() {
    vi greed = {1,2,3};
    vi size = {1,1};
    cout << assignCookies(greed, size) << endl;
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