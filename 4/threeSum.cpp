#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

vector<vector<int>> threeSumBetter(vector<int> &nums)
{
    set<vector<int>> st;
    
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        set<int> hashSet;
        for (int j = i + 1; j < n; j++)
        {
            int third = -(nums[i] + nums[j]);
            if (hashSet.find(third) != hashSet.end())
            {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashSet.insert(nums[j]);
        }
    }
    
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> threeSumOptimal(vector<int> &nums){
    vvi ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i=0;i<n;i++){
        // removing duplicates i
        if(i>0 && nums[i] == nums[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j<k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum<0){
                j++;
            }else if(sum>0){
                k--;
            }else{
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                // removing duplicates j & k
                while(j<k && nums[j] == nums[j-1]) j++;
                while(j<k && nums[k] == nums[k+1]) k--;
            }
        }
    }
    return ans;
}

void print(vvi ans){
    for(auto it: ans){
        for(auto iter: it){
            cout << iter << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void solve()
{
    vi nums = {-1, -1, 2, 0, 1};
    vvi ans = threeSumBetter(nums);
    print(ans);
    vvi ans2 = threeSumOptimal(nums);
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