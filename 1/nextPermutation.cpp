#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

void print(vi nums){
    for(auto it: nums)
        cout << it << " ";
    cout << endl;
}

// TC - O(n! . n) [n! to generate permutations]
// void brute(vi nums){} 

// STL
void better(vi &nums){
    next_permutation(nums.begin(), nums.end());
}

// TC - O(3n)
// SC - O(1)
void optimal(vi &nums){
    int n = nums.size();
    int ind = -1;
    for(int i=n-2;i>=0;i--){
        if(nums[i] < nums[i+1]){
            ind = i;
            break;
        }
    }
    
    if(ind == -1){
        reverse(nums.begin(), nums.end());
    }

    for(int i=n-1;i>ind;i--){
        if(nums[i] > nums[ind]){
            swap(nums[i], nums[ind]);
            break;
        }
    }

    reverse(nums.begin() + ind+1, nums.end());
}

void solve() {
    vi nums = {3, 1, 2};
    cout << "Num: " << endl;
    print(nums);
    // Steps: [just explain because the process is big]
    // 1. Generate all possible permutations in sorted manner with recursion
    // 2. linear search
    // 3. next index
    // brute();
    
    // C++ STL - next_permutation(nums.begin(), nums.end())
    cout << endl;
    cout << "Better: " << endl;
    better(nums);
    print(nums);
    
    // Steps:
    // 1. Find the breakpoint where a[i] < a[i+1]
    // 2. Find > a[i] but the smallest one on the right of breakpoint. So, you can stay close
    // 3. Then, put the remaining numbers in reversed manner
    nums = {3, 1, 2};
    cout << endl;
    cout << "Optimal: " << endl;
    optimal(nums);
    print(nums);
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