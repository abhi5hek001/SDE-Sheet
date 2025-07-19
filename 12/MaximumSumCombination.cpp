#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

vector<int> topKSumPairs(vector<int> &a, vector<int> &b, int k)
{
    int n1 = a.size();
    int n2 = b.size();
    vector<int> ans;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    // (sum, (i, j))
    priority_queue<pair<int, pair<int, int>>> pq;
    // (i, j)
    set<pair<int, int>> st;
    pq.push({a.back() + b.back(), {n1 - 1, n2 - 1}});
    st.insert({n1 - 1, n2 - 1});
    while (k-- && !pq.empty())
    {
        auto it = pq.top();
        int sum = it.first;
        int i = it.second.first;
        int j = it.second.second;
        ans.push_back(sum);
        pq.pop();

        if (i - 1 >= 0 && st.find({i - 1, j}) == st.end())
        {
            pq.push({a[i - 1] + b[j], {i - 1, j}});
            st.insert({i - 1, j});
        }
        if (j - 1 >= 0 && st.find({i, j - 1}) == st.end())
        {
            pq.push({a[i] + b[j - 1], {i, j - 1}});
            st.insert({i, j - 1});
        }
    }
    return ans;
}

void solve()
{
    vi a = {1,4,2,3};
    vi b = {2,5,1,6};
    int k = 2;
    vi ans = topKSumPairs(a, b, k);
    cout << "Printing Top K sum pairs" << endl;
    for(auto it: ans){
        cout << it << " ";
    } cout << endl;
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