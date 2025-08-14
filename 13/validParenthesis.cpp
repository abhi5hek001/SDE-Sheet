#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

bool isValid(string s) {
       stack<char> st;
       for(char ch: s){
            if(ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else{
                if(st.empty()) return false;
                char topEl = st.top();
                st.pop();
                if(
                ch == ')' && topEl != '(' ||
                ch == '}' && topEl != '{' ||
                ch == ']' && topEl != '[')
                return false;
            }
       } 
       return st.empty();
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