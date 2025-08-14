#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> nge(n);
    stack<int> st;
    for (int i = (2 * n) - 1; i >= 0; i--)
    {
        int num = nums[i % n];
        while (!st.empty() && st.top() <= num)
        {
            st.pop();
        }
        if (i < n)
        {
            nge[i] = st.empty() ? -1 : st.top();
        }
        st.push(num);
    }
    return nge;
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