#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

vvi fourSumBetter(vi nums, int target)
{
    set<vector<int>> st;

    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<long long> hashSet;
            for (int k = j + 1; k < n; k++)
            {
                long long sum = nums[i] + nums[j];
                sum += nums[k]; 
                long long fourth = target - sum;
                if (hashSet.find(fourth) != hashSet.end())
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int) fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashSet.insert(nums[k]);
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vvi fourSumOptimal(vi nums, int target)
{
    int n = nums.size();
    vvi ans;
    sort(nums.begin(), nums.end());
    for(int i=0;i<n;i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j>i+1 && nums[j] == nums[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k<l){
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                sum += nums[l];
                if(sum > target){
                    l--;
                }else if(sum < target){
                    k++;
                }else{
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    l--;
                    k++;
                    while(k<l && nums[k] == nums[k-1]) k++;
                    while(k<l && nums[l] == nums[l+1]) l--; 
                }
            }
        }
    }
    return ans;
}

void print(vvi ans)
{
    for (auto it : ans)
    {
        for (auto iter : it)
        {
            cout << iter << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void solve()
{
    int target = 0;
    vi nums = {1, 0, -1, 0, -2, 2};
    vvi ans = fourSumBetter(nums, target);
    print(ans);
    vvi ans2 = fourSumOptimal(nums, target);
    print(ans2);
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