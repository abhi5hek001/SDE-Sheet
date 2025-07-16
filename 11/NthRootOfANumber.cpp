#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

double multiply(double number, int n){
    double ans = 1.0;
    for(int i=1;i<=n;i++){
        ans = ans * number;
    }
    return ans;
}

void getNthRoot(int n, int m){
    double low = 1;
    double high = m;
    double eps = 1e-6;
    while((high-low) > eps){
        double mid = low + (high-low)/2;
        if(multiply(mid, n) > m) high = mid;
        else low = mid;
    }
    cout << low << " " << high << endl;
    cout << pow(m, (double)(1.0/(double)n));
}

void solve() {
    int n = 5;
    int m = 1025;
    getNthRoot(n, m);
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