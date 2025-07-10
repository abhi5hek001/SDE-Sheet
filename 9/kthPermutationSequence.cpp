#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

void kthPermutation(int n, int k, string &ans){
    int fact = 1;
    vi numbers;
    for(int i=1;i<n;i++){
        fact *= i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    k--;
    while(true){
        ans = ans + to_string(numbers[k/fact]);
        numbers.erase(numbers.begin() + k/fact);
        if(numbers.size() == 0) 
            break;
        k = k % fact;
        fact = fact / numbers.size();
    }
}

void solve() {
    int n = 4;
    int k = 17;
    string ans = "";
    kthPermutation(n, k, ans);
    cout << ans;
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