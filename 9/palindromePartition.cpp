#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;
using vvs = vector<vs>;

bool isPalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}

void palindromePartition(int ind, string s, vs &path, vvs &res)
{
    if (ind == s.size())
    {
        res.push_back(path);
        return;
    }
    for (int i = ind; i < s.size(); i++)
    {
        if (isPalindrome(s, ind, i))
        {
            path.push_back(s.substr(ind, i - ind + 1));
            palindromePartition(i + 1, s, path, res);
            path.pop_back();
        }
    }
}

void print(vvs res){
    for(auto it: res){
        for(auto iter: it){
            cout << iter << " ";
        }
        cout << endl;
    }
}

void solve()
{
    string str = "aabb";
    vvs res;
    vs path;
    palindromePartition(0, str, path, res);
    print(res);
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