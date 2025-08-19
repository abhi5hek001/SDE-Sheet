#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

int repeatedStringMatch(string a, string b)
{
    // 2 strings => a, b
    // b = prefix + n*a + suffix => n+2
    // b = prefix + n*a => n+1
    // b = n*a + suffix => n+1
    // b = n*a => n

    int b_len = b.size();
    int a_len = a.size();
    int n = b_len / a_len;
    int cnt = n;
    string na = "";

    while (cnt--)
    {
        na = na + a;
    }

    if (na.find(b) != string::npos)
    {
        return n;
    }
    na = na + a;
    if (na.find(b) != string::npos)
    {
        return n + 1;
    }
    na = na + a;
    if (na.find(b) != string::npos)
    {
        return n + 2;
    }

    return -1;
}

// Build the LPS (Longest Prefix Suffix) array
    vector<int> buildLPS(string &pat) {
        int m = pat.size();
        vector<int> lps(m, 0);
        int len = 0, i = 1;

        while(i < m){
            if(pat[i] == pat[len]){
                len++;
                lps[i] = len;
                i++;
            } else {
                if(len != 0){
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    bool kmp(string str, string pat){
        int n = str.size();
        int m = pat.size();

        vector<int> lps = buildLPS(pat);

        int i = 0, j = 0; // i → str, j → pat
        while(i < n){
            if(str[i] == pat[j]){
                i++; j++;
                if(j == m) return true; // full match
            } else {
                if(j != 0){
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }

    int repeatedStringMatchUsingKMP(string a, string b) {
        // 2 strings => a, b
        // b = prefix + n*a + suffix => n+2
        // b = prefix + n*a => n+1
        // b = n*a + suffix => n+1
        // b = n*a => n

        int b_len = b.size();
        int a_len = a.size();
        int n = b_len / a_len;
        int cnt = n;
        string na = "";

        while(cnt--){
            na = na + a;
        }

        if(kmp(na, b)){
            return n;
        }
        na = na + a;
        if(kmp(na, b)){
            return n+1;
        }
        na = na + a;
        if(kmp(na, b)){
            return n+2;
        }

        return -1;
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