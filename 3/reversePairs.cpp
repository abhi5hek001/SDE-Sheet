#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

// TC - O(n)
void merge(vector<int> &nums, int low, int mid, int high){
    int left = low;
    int right = mid+1;
    vector<int> temp;
    while(left <= mid && right <= high){
        if(nums[left] <= nums[right]){
            temp.push_back(nums[left++]);
        } else { 
            temp.push_back(nums[right++]);
        }
    }
    while(left <= mid){
        temp.push_back(nums[left++]);
    }
    while(right <= high){
        temp.push_back(nums[right++]);
    }
    for(int i=low; i <= high; i++){
        nums[i] = temp[i-low];
    }
}

// O(n)
int countReversePairs(vi nums, int low, int mid, int high){
    int right = mid + 1;
    int cnt = 0;
    for(int i=low;i<=mid;i++){
        while(right <= high && nums[i] > 2*nums[right]) 
            right++;
        cnt += (right - (mid+1));
    }
    return cnt;
}

// TC - O(log n)
int mergeSort(vector<int> &nums, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = low + (high - low) / 2;
    cnt += mergeSort(nums, low, mid);
    cnt += mergeSort(nums, mid + 1, high);
    cnt += countReversePairs(nums, low, mid, high);
    merge(nums, low, mid, high);
    return cnt;
}

void solve()
{
    int ans;
    vi nums = {1,3,2,3,1};
    int n = nums.size();
    ans = mergeSort(nums, 0, n-1);
    cout << ans << endl;
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