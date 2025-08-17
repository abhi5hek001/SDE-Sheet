#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

class MinStack
{
public:
    MinStack()
    {
        mini = LLONG_MAX;
    }
    // Brute Approach
    // TC - O(1) && SC - O(2N)
    // stack<pair<int,int>> st; // {value, minimum value seen till now}
    // void push(int val) {
    //     if(st.empty()){
    //         st.push({val,val});
    //     } else {
    //         st.push({val,min(val,st.top().second)});
    //     }
    // }

    // void pop() {
    //     st.pop();
    // }

    // int top() {
    //     return st.top().first;
    // }

    // int getMin() {
    //     return st.top().second;
    // }

    // Optimal
    stack<int> st;
    long long mini;
    void push(int val)
    {
        long long x = val;
        if (st.empty())
        {
            mini = x;
            st.push(x);
        }
        else
        {
            if (x > mini)
                st.push(x);
            else
            {
                // ***************
                st.push(2LL * x - mini);
                // ***************
                mini = x;
            }
        }
    }

    void pop()
    {
        if (st.empty())
            return;
        long long x = st.top();
        st.pop();
        if (x < mini)
        {
            mini = 2LL * mini - x;
        }
        if (st.empty())
            mini = LLONG_MAX;
    }

    int top()
    {
        if (st.empty())
            return -1;
        long long x = st.top();
        return (x < mini) ? (int)mini : (int)x;
    }

    int getMin()
    {
        return (mini == LLONG_MAX) ? -1 : (int)mini;
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