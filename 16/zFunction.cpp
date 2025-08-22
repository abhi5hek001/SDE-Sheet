#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

// BRUTE
int strStr(string haystack, string needle)
{
    int n1 = haystack.size(), n2 = needle.size();
    for (int i = 0; i < n1; i++)
    {
        int j = 0, first = i;
        while (j < n2 && haystack[first] == needle[j])
        {
            j++;
            first++;
        }
        if (j == n2)
            return i;
    }
    return -1;
}

vector<int> buildZ(string &s)
{
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;

    for (int i = 1; i < n; i++)
    {
        if (i <= r)
        {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int strStr(string haystack, string needle)
{
    if (needle.empty())
        return 0;

    string combined = needle + "$" + haystack;
    vector<int> z = buildZ(combined);

    int m = needle.size();
    for (int i = 0; i < z.size(); i++)
    {
        if (z[i] == m)
        {
            return i - m - 1; // position in haystack
        }
    }
    return -1;
}

void solve()
{
    cout << "First occurrence: " << strStr("ababcabc", "abc") << endl;
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