#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

class StockSpanner
{
public:
    // vector<int> arr;
    // StockSpanner() {
    //     arr = {};
    // }

    // TC - O(number of days)
    // SC - O(total number of next calls)
    // int next(int price) {
    //     arr.push_back(price);
    //     int cnt = 1;
    //     for(int i = arr.size() - 2; i >= 0; i--){
    //         if(arr[i] <= price) cnt++;
    //         else break;
    //     }
    //     return cnt;
    // }

    // ********** OPTIMAL************
    stack<pair<int, int>> st; // {val, ind}
    int ind;
    StockSpanner()
    {
        st = stack<pair<int, int>>();
        ind = -1;
    }

    // Think if we have PGE for that element which violates the rule so, till that it is our answer
    int next(int price)
    {
        ind = ind + 1;
        while (!st.empty() && st.top().first <= price)
            st.pop();
        int ans = ind - (st.empty() ? -1 : st.top().second);
        st.push({price, ind});
        return ans;
    }
};

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