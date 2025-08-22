#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

vector<string> ConvertIntoVector(string version)
{
    vector<string> v;
    stringstream ss(version);
    string token = "";
    while (getline(ss, token, '.'))
    {
        v.push_back(token);
    }
    return v;
}
int compareVersion(string version1, string version2)
{
    vector<string> v1 = ConvertIntoVector(version1);
    vector<string> v2 = ConvertIntoVector(version2);
    int i = 0;
    int m = v1.size();
    int n = v2.size();
    while (i < m || i < n)
    {
        int a = i < m ? stoi(v1[i]) : 0;
        int b = i < n ? stoi(v2[i]) : 0;
        if (a < b)
            return -1;
        else if (a > b)
            return 1;
        else
            i++;
    }
    return 0;
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