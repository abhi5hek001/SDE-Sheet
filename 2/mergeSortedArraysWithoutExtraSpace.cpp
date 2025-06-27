#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

void mergeSortedArraysWithoutExtraSpace(vi &nums1, vi &nums2, int n, int m)
{
    int left = n - 1;
    int right = 0;
    while (left >= 0 && right < m)
    {
        if (nums2[right] <= nums1[left])
        {
            swap(nums2[right], nums1[left]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
}

void print(vi nums)
{
    for (auto it : nums)
        cout << it << " ";
    cout << endl;
}

void solve()
{
    vi nums1 = {1, 3, 3, 7};
    vi nums2 = {0, 2, 6, 8, 9};
    print(nums1);
    print(nums2);
    mergeSortedArraysWithoutExtraSpace(nums1, nums2, nums1.size(), nums2.size());
    cout << "After Sorting: " << endl;
    print(nums1);
    print(nums2);
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