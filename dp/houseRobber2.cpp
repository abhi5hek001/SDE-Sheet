#include <bits/stdc++.h>
using namespace std;
#include <chrono>

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

int robHouse(vector<int> &nums)
{
    int prev2 = 0;
    int prev = nums[0];
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
        {
            pick += prev2;
        }
        int notpick = prev;
        int curr = max(pick, notpick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int rob(vector<int> &nums)
{
    vector<int> temp1, temp2;
    int n = nums.size();
    if (n == 1)
        return nums[0];
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(nums[i]);
        if (i != n - 1)
            temp2.push_back(nums[i]);
    }
    return max(robHouse(temp1), robHouse(temp2));
}

void solve()
{
    auto start = chrono::high_resolution_clock::now();

    // Example usage:
    int n = 5;
    vi arr = {1,2,3,1};
    cout << "Result: " << rob(arr) << endl;

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