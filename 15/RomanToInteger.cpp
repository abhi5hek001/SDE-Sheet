#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

int romanToInt(string s)
{
    unordered_map<char, int> umap;
    umap['I'] = 1;
    umap['V'] = 5;
    umap['X'] = 10;
    umap['L'] = 50;
    umap['C'] = 100;
    umap['D'] = 500;
    umap['M'] = 1000;
    int n = s.length();
    int result = umap[s[n - 1]];
    //  IMPORTANT: Start from the end of the string
    // and compare each character with the next one
    for (int i = n - 1; i > 0; i--)
    {
        if (umap[s[i]] > umap[s[i - 1]])
            result -= umap[s[i - 1]];
        else
            result += umap[s[i - 1]];
    }
    return result;
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