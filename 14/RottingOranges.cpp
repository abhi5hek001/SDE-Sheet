#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

int rottenOranges(vvi grid, int n, int m)
{
    vvi visited(n, vi(m, 0));
    queue<pair<pair<int, int>, int>> q;
    int cntFresh = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                visited[i][j] = 1;
            }
            else if (grid[i][j] == 1)
                cntFresh++;
        }
    }
    int time = 0;
    vi delrow = {-1, 0, 1, 0};
    vi delcol = {0, 1, 0, -1};
    int cnt = 0;
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        time = max(time, t);
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                q.push({{nrow, ncol}, t + 1});
                visited[nrow][ncol] = 1;
                cnt++;
            }
        }
    }
    if (cnt != cntFresh)
        return -1;
    return time;
}

void solve()
{
    vvi grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}};

    int ans = rottenOranges(grid, grid.size(), grid[0].size());
    cout << "Ans: " << ans;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}