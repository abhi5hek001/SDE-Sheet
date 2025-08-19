#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

// Approach 1: Reverse the entire string, then reverse each word in the reversed string.
string reverseWords(string s)
{
    int n = s.length();
    string ans = "";

    reverse(s.begin(), s.end());

    for (int i = 0; i < n; i++)
    {
        string word = "";
        while (i < n && s[i] != ' ')
        {
            word += s[i];
            i++;
        }

        reverse(word.begin(), word.end());
        if (word.length() > 0)
        {
            ans += " " + word;
        }
    }

    return ans.substr(1);
}

// Approach 2
// string reverseWords(string s) {
//     int n = s.length();
//     string ans = "";

//     for(int i=0;i<n;i++){
//         if(s[i] == ' ') continue;
//         string word = "";
//         while(i<n && s[i] != ' '){
//             word += s[i];
//             i++;
//         }

//         if(word.length() > 0){
//             ans = word + (ans.empty() ? "" : " ") + ans;
//         }
//     }

//     return ans;
// }

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