#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

// optimal for negatives && better for positives
int subarraySumEqualsK(vi nums, long long k)
{
    unordered_map<long long, int> preSumMap;
    int longest = 0;
    long long presum = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        presum += nums[i];
        if (presum == k)
        {
            longest = max(longest, i + 1);
        }
        int rem = presum - k;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            longest = max(longest, len);
        }
        // to avoid the violation in case of zeroes  
        if (preSumMap.find(presum) == preSumMap.end())
        {
            preSumMap[presum] = i;
        }
    }
    
    return longest;
}

// optimal for positives
int subarraySumEqualsKOptimal(vi nums, long long k){
    int left = 0, right = 0;
    long long sum = 0;
    int maxLen = 0;
    int n = nums.size();
    while(right < n){
        sum += nums[right];
        while(left <= right && sum > k){
            sum -= nums[left];
            left++;
        }
        if(sum == k){
            maxLen = max(maxLen, right-left+1);
        }
        right++;
    }
    return maxLen;
}


void solve()
{
    vi nums = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    long long k = 3;
    cout << subarraySumEqualsK(nums, k) << endl;
    cout << subarraySumEqualsKOptimal(nums, k) << endl;
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