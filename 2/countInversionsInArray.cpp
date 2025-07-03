#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

// TC - O(n)
int merge(vector<int> &nums, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    int cnt = 0;
    vector<int> temp;
    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            temp.push_back(nums[left++]);
        }
        else
        {
            temp.push_back(nums[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(nums[left++]);
    }
    while (right <= high)
    {
        temp.push_back(nums[right++]);
    }
    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }
    
    return cnt;
}

// TC - O(log n)
int mergeSort(vector<int> &nums, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = low + (high - low) / 2;
    cnt += mergeSort(nums, low, mid);
    cnt += mergeSort(nums, mid + 1, high);
    cnt += merge(nums, low, mid, high);
    return cnt;
}

void solve()
{
    int cnt = 0;
    vi nums = {5, 3, 2, 4, 1};
    cnt = mergeSort(nums, 0, nums.size()-1);
    cout << "Inverted Pairs are: " << cnt << endl;
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