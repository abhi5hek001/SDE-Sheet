#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

int majorityElementBetter(vector<int>& nums) {
    int n = nums.size();
    map<int, int> mp;
    for(int i=0;i<n;i++){
        mp[nums[i]]++;
    }
    for(auto it: mp){
        if(it.second > n/2)
            return it.first;
    }
    return -1;
}

int majorityElementOptimal(vector<int> &nums)
{
    int el;
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            el = nums[i];
        }
        else if (nums[i] == el)
            cnt++;
        else
            cnt--;
    }
    int cnt1 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == el)
            cnt1++;
    }
    if (cnt1 > (nums.size() / 2))
        return el;
    return -1;
}

void solve()
{
    vi nums1 = {2,2,3,3,1,2,2};
    vi nums2 = {7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};
    vi nums3 = {7,7,5,7,5,1,5,7,5,5,7,7,1,1,1,1};
    cout << majorityElementBetter(nums1) << endl;
    cout << majorityElementOptimal(nums2) << endl;
    cout << majorityElementOptimal(nums3) << endl;
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