#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

vector<int> majorityElementOptimal(vector<int> &nums)
{
    int el1, el2;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (cnt1 == 0 && nums[i] != el2)
        {
            cnt1 = 1;
            el1 = nums[i];
        }
        else if(cnt2 == 0 && nums[i] != el1){
            cnt2 = 1;
            el2 = nums[i];
        }
        else if (nums[i] == el1)
            cnt1++;
        else if(nums[i] == el2)
            cnt2++;
        else{
            cnt1--; 
            cnt2--;
        }
    }
    cnt1 = 0, cnt2 = 0;
    vector<int> ls;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == el1)cnt1++;
        if (nums[i] == el2) cnt2++;
    }
    int mini = (int) ((nums.size()/3) + 1);
    if (cnt1 >= mini)
        ls.push_back(el1);
    if (cnt2 >= mini)
        ls.push_back(el2);
    return ls;
}

void solve()
{
    vi nums1 = {1, 1, 1, 3, 3, 2, 2, 2};
    vi ans = majorityElementOptimal(nums1);
    for(auto it: ans){
        cout << it << " ";
    }
    cout << endl;
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