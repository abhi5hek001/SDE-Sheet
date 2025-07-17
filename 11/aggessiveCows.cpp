#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

bool canWePlace(vi &stalls, int cows, int dist)
{
    int cntCows = 1, last = stalls[0];
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - last >= dist)
        {
            cntCows++;
            last = stalls[i];
        }
    }
    if (cntCows < cows)
        return false;
    else
        return true;
}

int aggressiveCows(vector<int> &stalls, int cows)
{
    int maxi = *max_element(stalls.begin(), stalls.end());
    int mini = *min_element(stalls.begin(), stalls.end());
    sort(stalls.begin(), stalls.end()); // important step
    
    // Brute Approach 
    // for(int i=1;i<=(maxi-mini);i++){
    //     if(canWePlace(stalls, cows, i)) continue;
    //     else return (i-1);
    // }
        
    // Optimal Approach - Binary Search
    int low = 1;
    int high = maxi - mini;
    int ans = 0;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (canWePlace(stalls, cows, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}

void solve()
{
    vi stalls = {0, 3, 4, 7, 10, 9};
    sort(stalls.begin(), stalls.end());
    int cows = 4;
    cout << aggressiveCows(stalls, cows) << endl;
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