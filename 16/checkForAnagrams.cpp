#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

 bool isAnagram(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m!=n){
            return false;
        }
        else{
            int count[26] = {0};
            for(int i=0;i<m;i++){
                count[s[i] - 'a']++;
            }
            for(int i=0;i<n;i++){
                count[t[i] - 'a']--;
            }
            for(int i=0;i<26;i++){
                if(count[i]!=0){
                    return false;
                }
            }
        }
        return true;
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