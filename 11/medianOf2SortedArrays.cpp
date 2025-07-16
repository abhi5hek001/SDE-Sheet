#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

double findMedianBetter(vi nums1, int n1, vi nums2, int n2){
    int i = 0, j = 0;
    int n = n1 + n2;
    int ind2 = n/2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int el1 = -1, el2 = -1;
    while(i<n1 && j<n2){
        if(nums1[i] < nums2[j]){
            if(cnt == ind1) el1 = nums1[i];
            if(cnt == ind2) el2 = nums1[i];
            cnt++;
            i++;
        }
        else{
            if(cnt == ind1) el1 = nums2[j];
            if(cnt == ind2) el2 = nums2[j];
            cnt++;
            j++;    
        }
    }
    while(i<n1){
        if(cnt == ind1) el1 = nums1[i];
        if(cnt == ind2) el2 = nums1[i];
        cnt++;
        i++;        
    }
    while(j<n2){    
        if(cnt == ind1) el1 = nums2[j];
        if(cnt == ind2) el2 = nums2[j];
        cnt++;
        j++;        
    }

    if(n%2 == 1) return el2;
    return ((double)(el1 + el2)) / 2.0;
}

double findMedianOptimal(vi nums1, int n1, vi nums2, int n2){
    
}

void solve() {
    vi nums1 = {1,3,4,7,10,12};
    vi nums2 = {2,3,6,15};
    cout << findMedianBetter(nums1, nums1.size(), nums2, nums2.size()) << endl;
    cout << findMedianOptimal(nums1, nums1.size(), nums2, nums2.size()) << endl;
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