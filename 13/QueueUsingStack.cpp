#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

class MyQueue {
public:
    MyQueue() {}

    stack<int> s1, s2;

// Heavy push method
    // void push(int x) {
    //     while (!s1.empty()) {
    //         s2.push(s1.top());
    //         s1.pop();
    //     }
    //     s1.push(x);
    //     while (!s2.empty()) {
    //         s1.push(s2.top());
    //         s2.pop();
    //     }
    // }

    // int pop() {
    //     int temp = s1.top();
    //     s1.pop();
    //     return temp;
    // }

    // int peek() {
    //     return s1.top();
    // }

    // bool empty() { 
    //     return s1.empty() && s2.empty();
    // }
    
// Heavy pop and peek method
    void push(int x){
        s1.push(x);
    }

    int pop() {
        if (!s2.empty()){
            int topval = s2.top();
            s2.pop();
            return topval;
        }
        else {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            int topval = s2.top();
            s2.pop();
            return topval;
        }
    }

    int peek() {
        if (!s2.empty()) return s2.top();
        else {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }

    bool empty() { 
        return s1.empty() && s2.empty();
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