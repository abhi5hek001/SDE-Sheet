#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

// Recursive approach => TLE Error
// TC = O(3^n)
// SC = O(n)
// bool RecursiveApproach(string s, int ind, int cnt) {
//     if (cnt < 0)
//         return false;
//     if (ind == s.size()) {
//         return (cnt == 0);
//     }
//     if (s[ind] == '(') {
//         return RecursiveApproach(s, ind + 1, cnt + 1);
//     }
//     if (s[ind] == ')') {
//         return RecursiveApproach(s, ind + 1, cnt - 1);
//     }
//     return RecursiveApproach(s, ind + 1, cnt + 1) ||
//            RecursiveApproach(s, ind + 1, cnt) ||
//            RecursiveApproach(s, ind + 1, cnt - 1);
// }
// DP Solution => will read later
// TC = O(n^2)
// SC = O(n^2)

// Greedy Approach
// TC = O(n)
// SC = O(1)
bool GreedyApproach(string s)
{
    int min = 0;
    int max = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            min += 1;
            max += 1;
        }
        else if (s[i] == ')')
        {
            min -= 1;
            max -= 1;
        }
        else
        {
            min -= 1;
            max += 1;
        }
        if (min < 0)
            min = 0;
        if (max < 0)
            return false;
    }
    return (min == 0);
}
bool checkValidString(string s)
{
    // return RecursiveApproach(s, 0, 0);
    return GreedyApproach(s);
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