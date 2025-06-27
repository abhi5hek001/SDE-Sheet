#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

// TC - O(2n) + O(n logn)
vector<vector<int>> merge(vector<vector<int>> &nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    // O(n logn)
    sort(nums.begin(), nums.end());
    // O(2n)
    for (int i = 0; i < n; i++)
    {
        int start = nums[i][0];
        int end = nums[i][1];
        if (!ans.empty() && end <= ans.back()[1])
        {
            // that pair is already included in the ans
            continue;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j][0] <= end)
            {
                end = max(end, nums[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

// TC - O(n) + O(n logn)
vector<vector<int>> mergeOptimal(vector<vector<int>> &nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        // adding in the ans, if no further extension possible
        if (ans.empty() || nums[i][0] > ans.back()[1])
        {
            ans.push_back(nums[i]);
        }
        // when extension is possible
        else
        {
            ans.back()[1] = max(ans.back()[1], nums[i][1]);
        }
    }
    return ans;
}

void print(vvi nums)
{
    for (auto it : nums)
    {
        for (auto iter : it)
        {
            cout << iter << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void solve()
{
    vvi nums = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    print(nums);
    vvi ans = merge(nums);
    cout << "Brute: " << endl;
    print(ans);
    nums = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vvi ans2 = mergeOptimal(nums);
    cout << "Optimal: " << endl;
    print(ans2);
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