#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

bool isSafe(int node, vi &color, vvi &adj, int V, int col){
    for(int nb: adj[node]){
        if(color[nb] == col) return false;
    }
    return true;
}

bool mColoring(int node, vvi &adj, vi &color, int m, int V){
    if(node == V) return true;

    for(int i=1;i <= m;i++){
        if(isSafe(node, color, adj, V, i)){
            color[node] = i;
            if(mColoring(node+1, adj, color, m, V)) 
                return true;
            color[node] = 0;
        }
    }
    return false;
}

void print(vi &color){
    for(auto it: color){
        cout << it << " ";
    }
    cout << endl;
}

void solve() {
    int V = 5;
    vvi edges = {{0, 4}, {1, 2}, {1, 0}, {2, 0}, {2, 3}, {2, 4}};
    vvi adj(V);
    for(auto &e: edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    int m = 3;
    vector<int> color(V, 0);
    print(color);
    mColoring(0, adj, color, m, V);
    print(color);
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