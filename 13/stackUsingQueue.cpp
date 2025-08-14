#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

class MyStack {
public:
    MyStack() {
    }

    queue<int> q;
    
    void push(int x) {
        q.push(x);
        int size = q.size();
        for(int i= 1;i<size;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int topval = q.front();
        q.pop();
        return topval;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.size() == 0) return true;
        return false;
    }
};

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