#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

void rotateMatrix(vector<vector<int>> &nums, int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        for (int j = i + 1; j <= n - 1; j++)
        {
            swap(nums[i][j], nums[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(nums[i].begin(), nums[i].end());
    }
}

void print(vvi nums){
    for(auto it: nums){
        for(auto iter: it){
            cout << iter << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void solve()
{
    vvi nums = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    print(nums);
    rotateMatrix(nums, nums.size());
    print(nums);
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