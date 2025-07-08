#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

int trappingRainwater(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = height[0];
    for (int i = 1; i < n; i++)
        leftMax[i] = max(height[i], leftMax[i - 1]);

    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
        rightMax[i] = max(height[i], rightMax[i + 1]);

    int water = 0;
    for (int i = 0; i < n; i++)
        water += min(leftMax[i], rightMax[i]) - height[i];

    return water;
}

int trappingRainwaterBetter(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    vector<int> rightMax(n);
    rightMax[n - 1] = height[n - 1];

    // Fill rightMax from right to left
    for (int i = n - 2; i >= 0; i--)
        rightMax[i] = max(height[i], rightMax[i + 1]);

    int water = 0;
    int leftMax = height[0];

    // Traverse from left to right, compute water using leftMax and rightMax
    for (int i = 1; i < n - 1; i++) {
        leftMax = max(leftMax, height[i]);
        int minHeight = min(leftMax, rightMax[i]);
        water += max(0, minHeight - height[i]);
    }

    return water;
}

int trappingRainwaterOptimal(vector<int>& height) {
    int n = height.size();
    int leftMax = 0, rightMax = 0, total = 0, l = 0, r = n-1;
    while(l<r){
        if(height[l] <= height[r]){
            if(leftMax > height[l]){
                total += leftMax - height[l];
            }
            else{
                leftMax = height[l];
            }
            l++;
        }
        else{
            if(rightMax > height[r]){
                total += rightMax - height[r];
            }
            else{
                rightMax = height[r];
            }
            r--;
        }
    }
    return total;
}

void solve() {
    vi height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trappingRainwater(height) << endl;
    cout << trappingRainwaterBetter(height) << endl;
    cout << trappingRainwaterOptimal(height) << endl;
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