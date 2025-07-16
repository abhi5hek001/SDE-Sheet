#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

int upperbound(vi arr, int x){
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = n;
    while(low <= high){
        int mid = (low + high) >> 1;
        if(arr[mid] > x){
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int findSmallerAndEqualElements(vvi matrix, int x){
    int cnt = 0;
    for(int i=0;i<matrix.size();i++){
        cnt += upperbound(matrix[i], x);
    }
    return cnt;
}

int findMatrixMedian(vvi matrix, int n, int m){
    int low = INT_MAX, high = INT_MIN;
    for(int i=0;i<n;i++){
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m-1]);
    }
    while(low <= high){
        int mid = (low+high) >> 1;
        int smallerEquals = findSmallerAndEqualElements(matrix, mid); // all elements that are smaller and equal to mid
        if(smallerEquals <= (n*m)/2){
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return low;
}

void solve() {
    vvi matrix = {
        {1,4,6,9},
        {3,5,7,8},
        {2,3,6,9}
    };
    cout << findMatrixMedian(matrix, matrix.size(), matrix[0].size()) << endl;
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