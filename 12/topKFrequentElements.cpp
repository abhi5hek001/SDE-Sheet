#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

vi topKMostFrequentElements(vi &nums, int k)
{
    unordered_map<int, int> freq;
    for (int num : nums)
    {
        freq[num]++;
    }

    // Min-heap by frequency
    priority_queue<pii, vector<pii>, greater<pii>> minHeap;

    for (auto it = freq.begin(); it != freq.end(); ++it)
    {
        int num = it->first;
        int count = it->second;
        minHeap.push({count, num});
        if (minHeap.size() > k)
            minHeap.pop();
    }

    vi ans;
    while (!minHeap.empty())
    {
        ans.push_back(minHeap.top().second);
        minHeap.pop();
    }
    reverse(ans.begin(), ans.end()); // Optional, to have highest freq first
    return ans;
}

 vector<int> topKMostFrequentElementsOptimal(vector<int>& nums, int k) {
        // {number, count}
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);

        for (int n : nums) {
            count[n]++;
        }

       for (auto& it : count) {
    int n = it.first;
    int c = it.second;
    freq[c].push_back(n);
}


        vector<int> res;
        for (int i = nums.size(); i > 0; --i) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }

        return res;
    }

void solve()
{
    vi nums = {1, 1, 1, 1, 2, 2, 3};
    int k = 2;

    cout << "Brute" << endl;
    vi ans = topKMostFrequentElements(nums, k);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    cout << "Optimal" << endl;
    vi ans2 = topKMostFrequentElementsOptimal(nums, k);
    for (auto it : ans2)
    {
        cout << it << " ";
    }
    cout << endl;
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