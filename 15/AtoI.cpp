#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

int myAtoi(string s)
{
    int len = s.length();
    int i = 0, out = 0, sign = 1;
    while (i < len && s[i] == ' ')
        i++;

    if (i == len)
        return 0;

    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }

    else if (s[i] == '+')
        i++;

    while (s[i] >= '0' && s[i] <= '9')
    {
        int digit = (s[i] - '0');
        // out*10 + digit > INT_MAX ⟺ out > (INT_MAX - digit)/10
        if (out > (INT_MAX - digit) / 10)
        {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        out = out * 10 + digit;
        i++;
    }

    return sign * out;
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