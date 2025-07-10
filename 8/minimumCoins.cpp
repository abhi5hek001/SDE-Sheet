#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

vi minimumCoins(vi &deno, int n, int V){
    vi ans;
    for(int i=n-1;i>=0;i--){
        while(V >= deno[i]){
            V -= deno[i];
            ans.push_back(deno[i]);
        }
    }
    for(auto it: ans)
        cout << it << " ";
    cout << endl;
}

void solve() {
    vi denominations = {1,2,5,10,20,50,100,500,1000};
    int V = 49;
    minimumCoins(denominations, denominations.size(), V);
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