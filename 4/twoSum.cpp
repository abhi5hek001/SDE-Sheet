#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

vector<int> twoSumBetter(vector<int> &nums, int target)
{
    int n = nums.size();
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int number = nums[i];
        int rem = target - number;
        if (mp.find(rem) != mp.end())
        {
            return {mp[rem], i};
        }
        mp[number] = i;
    }
    return {-1, -1};
}

vi twoSumOptimal(vi nums, int target)
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;

    // for storing the value and indices of elements of array
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++){
        v.push_back({nums[i], i});
    }

    sort(v.begin(), v.end());
    while (left < right)
    {
        int sum = v[left].first + v[right].first;
        if (sum == target)
            return {v[left].second, v[right].second};
        else if (sum < target)
            left++;
        else
            right--;
    }
    return {-1, -1};
}

void solve()
{
    vi nums = {2, 6, 5, 8, 11};
    int target = 14;
    vi ans, ans2;
    ans = twoSumBetter(nums, target);
    cout << ans[0] << " " << ans[1] << endl;
    ans2 = twoSumOptimal(nums, target);
    cout << ans2[0] << " " << ans2[1] << endl;
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