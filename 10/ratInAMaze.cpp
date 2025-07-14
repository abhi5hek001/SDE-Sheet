#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;
using vs = vector<string>;
using vvs = vector<vs>;

// void findPath(int i, int j, vvi &mat, int n, vs &ans, string move, vvi &vis){
    //     if(i == n-1 && j== n-1) {
        //         ans.push_back(move); 
        //         return;
        //     }
        //     // downward
        //     if(i+1 < n && !vis[i+1][j] && mat[i+1][j] == 1){
            //         vis[i][j] = 1;
            //         findPath((i+1), j, mat, n, ans, move + 'D', vis);
            //         vis[i][j] = 0;
            //     }
            //     // left
            //     if(j-1 >= 0 && !vis[i][j-1] && mat[i][j-1] == 1){
                //         vis[i][j] = 1;
                //         findPath(i, (j-1), mat, n, ans, move + 'L', vis);
                //         vis[i][j] = 0;
                //     }
                //     // right    
                //     if(j+1 < n && !vis[i][j+1] && mat[i][j+1] == 1){
//         vis[i][j] = 1;
//         findPath(i, (j+1), mat, n, ans, move + 'R', vis);
//         vis[i][j] = 0;
//     }
//     // upward
//     if(i-1 >= 0 && !vis[i-1][j] && mat[i-1][j] == 1){
//         vis[i][j] = 1;
//         findPath((i+1), j, mat, n, ans, move + 'U', vis);
//         vis[i][j] = 0;
//     }
// }

void findPathOptimal(int i, int j, vvi &mat, int n, vs &ans, string move, vvi &vis, vi di, vi dj){
    if(i == n-1 && j == n-1) {
        ans.push_back(move);
        return;
    }
    string dir = "DLRU";
    for(int ind = 0;ind<4;ind++){
        int nexti = i + di[ind];
        int nextj = j + dj[ind];
        if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && mat[nexti][nextj] == 1){
            vis[nexti][nextj] = 1;
            findPathOptimal(nexti, nextj, mat, n, ans, move + dir[ind], vis, di, dj);
            vis[nexti][nextj] = 0;
        }
    }
}

void print(vs &ans){
    for (const auto &p : ans) cout << p << '\n';
}

vs ratInAMaze(vvi &mat, int n){
    vs ans;
    vvi vis(n, vi (n, 0));
    vi di = {1,0,0,-1};
    vi dj = {0,-1,1,0};
    // if(mat[0][0] == 1) {
    //     vis[0][0] = 1;
    //     findPath(0, 0, mat, n, ans, "", vis);
    // }   
    if(mat[0][0] == 1) {
        vis[0][0] = 1;
        findPathOptimal(0, 0, mat, n, ans, "", vis, di, dj);
    }
    return ans;
}


void solve() {
    vvi mat = {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };
    int N = 4;
    vs ans = ratInAMaze(mat, N);
    print(ans);
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