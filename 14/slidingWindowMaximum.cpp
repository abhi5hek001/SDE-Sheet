#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    // vector<int> ans;
    // int n = nums.size();
    // int maxi;
    // for (int i = k - 1; i < n; i++) {
    //     maxi = nums[i];
    //     for (int j = i - k + 1; j <= i; j++) {
    //         maxi = max(maxi, nums[j]);
    //     }
    //     ans.push_back(maxi);
    // }
    // return ans;

    // Monotonic stack (decreasing) - doubly deque
    // TC - O(2N) & SC - O(k) + O(n-k)
    vector<int> ans;
    deque<int> dq; // index
    for (int i = 0; i < nums.size(); i++)
    {
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();

        dq.push_back(i);
        if (i >= k - 1)
            ans.push_back(nums[dq.front()]);
    }
    return ans;
}

void solve()
{
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