#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

// Efficient Approach (Using Next Smaller / Previous Smaller):
// Brute force would be O(n²). Instead, we can use the concept of spans:
// For each element, find the length of the largest window in which it is the minimum.
// Then place that element as a candidate answer for that window size.
// Finally, fill in remaining entries by propagating maximums from right to left.

vector<int> maxOfMin(vector<int> &arr, int n)
{
    vector<int> res(n + 1, 0);
    vector<int> left(n), right(n);

    // Find previous smaller element
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    // Find next smaller element
    while (!st.empty())
        st.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    // Length of window where arr[i] is minimum
    for (int i = 0; i < n; i++)
    {
        int len = right[i] - left[i] - 1;
        res[len] = max(res[len], arr[i]);
    }

    // Fill the rest
    for (int i = n - 1; i >= 1; i--)
        res[i] = max(res[i], res[i + 1]);

    // Ignore index 0
    res.erase(res.begin());
    return res;
}

void solve()
{
    vi nums = {10, 20, 30, 50, 10, 70, 30};
    vi ans = maxOfMin(nums, nums.size());
    for (auto it : ans)
        cout << it << " ";
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