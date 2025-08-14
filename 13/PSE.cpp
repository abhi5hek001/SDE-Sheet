#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

vi PSE(vi &A){
    int n = A.size();
    vector<int> pse(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        int num = A[i];
        while(!st.empty() && st.top() >= num){
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(num);
    }
    return pse;
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