#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

int singleNonDuplicate(vector<int> &nums)
{
    int low = 0;
    int high = nums.size() - 2;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        // left half
        if (nums[mid] == nums[mid ^ 1])
        {
            low = mid + 1;
        }
        // right half
        else
        {
            high = mid - 1;
        }
    }
    return nums[low];
}

void solve()
{
    vi nums = {1,1,2,3,3,4,4,8,8};
    cout << singleNonDuplicate(nums) << endl;
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