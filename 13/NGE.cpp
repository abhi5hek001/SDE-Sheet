#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    stack<int> st;
    int n = nums2.size();
    unordered_map<int, int> nge;
    for (int i = n - 1; i >= 0; i--)
    {
        int num = nums2[i];
        while (!st.empty() && st.top() <= num)
            st.pop();
        if (st.empty())
            nge[num] = -1;
        else
            nge[num] = st.top();
        st.push(num);
    }
    vector<int> ans;
    for (auto num : nums1)
    {
        ans.push_back(nge[num]);
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