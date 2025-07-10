#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

void powerSet(vector<int> &nums, int ind, int n, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds); // Push the current subset

    for (int i = ind; i < n; i++)
    {
        ds.push_back(nums[i]);
        powerSet(nums, (i + 1), n, ds, ans);
        ds.pop_back(); // Backtrack
    }
}

void print(vvi ans)
{
    for (auto it : ans)
    {
        for (auto iter : it)
        {
            cout << iter << " ";
        }
        cout << endl;
    }
}

void solve()
{
    vi nums = {1,2,3};
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    powerSet(nums, 0, nums.size(), ds, ans);
    print(ans);
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