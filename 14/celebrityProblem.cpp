#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

vector<vector<int>> M;

bool knows(int a, int b)
{
    return M[a][b] == 1;
}

int findCelebrity(int n)
{
    int top = 0, bottom = n - 1;
    while (top <= bottom){
        if (top == bottom){
            for (int i = 0; i < n; i++){
                if (i == top)
                    continue;
                if (knows(top, i) == 0 && knows(i, bottom) == 1)
                    continue;
                else
                    return -1;
            }
            return top;
        }
        if (knows(top, bottom))
            top++;
        else if (knows(bottom, top))
            bottom--;
        else{
            top++;
            bottom--;
        }
        if (top > bottom)
            return -1;
    }
    return top;
}

void solve()
{
    M = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {0, 0, 0, 0}, // celeb: knows nobody
        {0, 0, 1, 0}};

    int n = M.size();
    cout << "Celebrity: " << findCelebrity(n);
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