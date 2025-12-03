#include <bits/stdc++.h>
using namespace std;
#include <chrono>

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

bool subsetSum(int ind, int n, int target, vector<int> &arr)
{
    vector<bool> prev(target + 1, false), curr(target + 1, false);

    prev[0] = true;

    if (arr[0] <= target)
        prev[arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            bool notTake = prev[j];

            bool take = false;
            if (arr[i] <= j)
                take = prev[j - arr[i]];

            curr[j] = take || notTake;
        }
        prev = curr;
    }
    return prev[target];
}

bool canPartition(vector<int> &nums)
{
    int totalsum = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        totalsum += nums[i];
    }
    if (totalsum % 2)
        return false;
    int target = totalsum / 2;
    return subsetSum(0, n, target, nums);
}

void solve()
{
    auto start = chrono::high_resolution_clock::now();

    // Example usage:
    vi arr = {2,3,3,3,4,5};
    cout << "Result: " << (canPartition(arr) ? "true" : "false");

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    cout << "\n\nTime taken: " << duration.count() << " ns\n";
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
