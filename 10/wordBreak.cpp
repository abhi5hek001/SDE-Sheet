#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

// Recursion
bool wordBreakRecursion(int idx, string s, int n, unordered_set<string> &st)
{
    if (idx >= n)
        return true;

    if (st.find(s) != st.end())
        return true;

    for (int l = 1; l <= n; l++)
    {
        string temp = s.substr(idx, l);
        if (st.find(temp) != st.end() && wordBreakRecursion(idx + l, s, n, st))
            return true;
    }
    return false;
}

bool solveRecursion(string s, vector<string> &wordDict)
{
    unordered_set<string> st;
    int n = s.size();

    for (string &word : wordDict)
    {
        st.insert(word);
    }

    return wordBreakRecursion(0, s, n, st);
}

// Memoization
bool wordBreakMemoization(int idx, string s, int n, unordered_set<string> &st, vector<int> &memo)
{
    if (idx >= n)
        return true;

    // memoization
    if (memo[idx] != -1)
        return memo[idx];

    if (st.find(s) != st.end())
        return memo[idx] = true;

    for (int l = 1; l <= n; l++)
    {
        string temp = s.substr(idx, l);
        if (st.find(temp) != st.end() && wordBreakMemoization(idx + l, s, n, st, memo))
            return memo[idx] = 1;
    }
    return memo[idx] = 0;
}

bool solveMemoization(string s, vector<string> &wordDict)
{
    unordered_set<string> st;
    int n = s.size();
    // memoization - 301 as s.length varies from 0 to 300
    vector<int> memo(s.size(), -1);

    for (string &word : wordDict)
    {
        st.insert(word);
    }

    return wordBreakMemoization(0, s, n, st, memo);
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
        string str = "applepenapple";
        vector<string> wordDict = {
            "apple",
            "pen"};
        cout << "Recursion" << endl;
        cout << (solveRecursion(str, wordDict) ? "true" : "false");
        cout << endl << "Memoization" << endl;
        cout << (solveMemoization(str, wordDict) ? "true" : "false");
    }
    return 0;
}