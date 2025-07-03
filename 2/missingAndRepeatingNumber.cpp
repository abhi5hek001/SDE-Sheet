#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<int> hash(n * n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            hash[grid[i][j]]++;
        }
    }
    int a = -1;
    int b = -1;
    for (int i = 0; i < hash.size(); i++)
    {
        if (hash[i] == 2)
            a = i;
        else if (hash[i] == 0)
            b = i;
        else
            continue;
    }
    return {a, b};
}

vector<int> findMissingAndRepeatedValuesOptimal(vector<vector<int>> &grid)
{
    int n = grid.size();
    int elem = n * n;
    long long sn = 1LL * (elem * (elem + 1)) / 2;
    long long s2n = 1LL * (elem * (elem + 1) * 1LL * (2 * elem + 1)) / 6;
    long long s = 0, s2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            s += grid[i][j];
            s2 += 1LL * grid[i][j] * grid[i][j];
        }
    }
    long long val1 = s - sn;   // x - y
    long long val2 = s2 - s2n; // x^2 - y^2
    val2 = val2 / val1;        // x + y
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}

void solve()
{
    vvi grid = {
        {9, 1, 7},
        {8, 9, 2},
        {3, 4, 6}};
    for (auto it : grid)
    {
        for (auto iter : it)
        {
            cout << iter << " ";
        }
        cout << endl;
    }
    cout << endl << "Better" << endl;
    vi ans = findMissingAndRepeatedValues(grid);
    cout << "Repeating Number: " << ans[0] << endl;
    cout << "Missing Number: " << ans[1] << endl;

    grid = {
        {9, 1, 7},
        {8, 9, 2},
        {3, 4, 6}};
    cout << endl << "Optimal 1" << endl;
    vi ans2 = findMissingAndRepeatedValuesOptimal(grid);
    cout << "Repeating Number: " << ans2[0] << endl;
    cout << "Missing Number: " << ans2[1] << endl;
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