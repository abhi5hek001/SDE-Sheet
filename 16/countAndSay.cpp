#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

string countAndSay(int n) {
        if(n == 1)
            return "1";

        string say = countAndSay(n-1);

        string res = "";
    
        for(int i=0;i<say.size();i++){
            char ch = say[i];
            int cnt = 1;
            while(i < say.size()-1 && say[i] == say[i+1]){
                cnt++;
                i++;
            }

            res = res + to_string(cnt) + string(1, ch);
        }
        return res;
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