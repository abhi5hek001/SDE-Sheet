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

// Build the LPS (Longest Prefix Suffix) array
vector<int> buildLPS(string &pat) {
    int m = pat.size();
    vector<int> lps(m, 0);
    int len = 0; // length of the previous longest prefix suffix
    int i = 1;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}   
// KMP algorithm to find occurrences of a pattern in a text
vector<int> KMP(string &text, string &pat) {    
    int n = text.size();
    int m = pat.size();
    vector<int> lps = buildLPS(pat);
    vector<int> result;

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n) {
        if (pat[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            result.push_back(i - j); // found a match
            j = lps[j - 1];
        } else if (i < n && pat[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return result;
}

void solve() {
    
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}