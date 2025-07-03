#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

int countSubarraySumEqualsK(vi nums, long long k)
{
    unordered_map<long long, int> preSumMap;
    long long presum = 0;
    int n = nums.size();
    preSumMap[0] = 1;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        presum += nums[i];
        count += preSumMap[presum - k];
        preSumMap[presum]++;
    }

    return count;
}

int countSubarraySumEqualsKOptimal(vi nums, long long k)
{
    int left = 0, right = 0;
    long long sum = 0;
    int cnt = 0;
    int n = nums.size();
    while (right < n)
    {
        sum += nums[right];
        while (left <= right && sum > k)
        {
            sum -= nums[left];
            left++;
        }
        if (sum == k)
        {
            cnt++;
        }
        right++;
    }
    return cnt;
}

void solve()
{
    vi nums = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    long long k = 3;
    cout << countSubarraySumEqualsK(nums, k) << endl;
    cout << countSubarraySumEqualsKOptimal(nums, k) << endl;
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