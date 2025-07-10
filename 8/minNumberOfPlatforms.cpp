#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

int findMinPlatforms(vi &arr, vi &dep){
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int Aptr = 0, Dptr = 0;
    int cnt = 0, maxCnt = 0;
    while(Aptr < arr.size()){
        if(arr[Aptr] <= dep[Dptr]){
            cnt++;
            Aptr++;
        }
        else{
            cnt--;
            Dptr++;
        }
        maxCnt = max(maxCnt, cnt);
    }
    return maxCnt;
}

void solve() {
    vi arr = {900,945,955,1100,1500,1800};
    vi dep = {920,1200,1130,1150,1900,2000};
    cout << findMinPlatforms(arr, dep) << endl;
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