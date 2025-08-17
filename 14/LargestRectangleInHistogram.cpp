#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

// vector<int> findNSE(vector<int> arr){
//     stack<int> st;
//     int n = arr.size();
//     vector<int> nse(n);
//     for(int i=n-1;i>=0;i--){
//         int num = arr[i];
//         while(!st.empty() && arr[st.top()] >= num){
//             st.pop();
//         }
//         nse[i] = st.empty() ? n : st.top();
//         st.push(i);
//     }
//     return nse;
// }
// vector<int> findPSE(vector<int> arr){
//     stack<int> st;
//     int n = arr.size();
//     vector<int> pse(n);
//     for(int i=0;i<n;i++){
//         int num = arr[i];
//         while(!st.empty() && arr[st.top()] >= num){
//             st.pop();
//         }
//         pse[i] = st.empty() ? -1 : st.top();
//         st.push(i);
//     }
//     return pse;
// }
// int largestRectangleArea(vector<int>& heights) {
//     vector<int> nse = findNSE(heights);
//     vector<int> pse = findPSE(heights);
//     int maxi = 0;
//     for(int i=0;i<heights.size();i++){
//         maxi = max(maxi, heights[i] * (nse[i] - pse[i] - 1));
//     }
//     return maxi;
// }

// Optimal Approach - Compute on the fly
int largestRectangleArea(vector<int> &heights)
{
    stack<int> st;
    int maxArea = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            int elem = st.top();
            st.pop();
            int nse = i;
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, heights[elem] * (nse - pse - 1));
        }
        st.push(i);
    }
    while (!st.empty())
    {
        int nse = heights.size();
        int elem = st.top();
        st.pop();
        int pse = st.empty() ? -1 : st.top();
        maxArea = max(maxArea, heights[elem] * (nse - pse - 1));
    }
    return maxArea;
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