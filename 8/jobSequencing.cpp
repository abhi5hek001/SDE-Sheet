#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

struct Job{
    int id;
    int profit;
    int deadline;
};

bool comp(Job val1, Job val2){
    return val1.profit > val2.profit;
}

pair<int, vector<int>> jobSequencing(vi &id, vi &deadline, vi &profit){
    int n = id.size();
    Job jobs[n];
    int maxDeadline = -1;
    for(int i=0;i<n;i++){
        jobs[i].id = id[i];
        jobs[i].deadline = deadline[i];
        jobs[i].profit = profit[i];
        maxDeadline = max(maxDeadline, deadline[i]);
    }
    sort(jobs, jobs+n, comp);

    vi sequence(maxDeadline+1, -1);
    int maxProfit = 0;
    for(int i=0;i<n;i++){
        for (int j = jobs[i].deadline; j >= 0; j--) {
            if(sequence[j] == -1){
                sequence[j] = jobs[i].id;
                maxProfit += jobs[i].profit;
                break;
            }
        }
    }
    return {maxProfit, sequence};
}

void solve() {
    // vi id = {6,3,4,2,5,8,1,7};
    // vi deadline = {2,6,6,5,4,2,4,2};
    // vi profit = {80,70,65,60,25,22,20,10};

    vi id = {1,2,3,4};
    vi deadline = {4,1,1,1};
    vi profit = {40,10,40,30};
    
    pair<int, vi> ans = jobSequencing(id, deadline, profit);
    cout << "Max Profit: " << ans.first << endl;
    vi sequence = ans.second;
    for(auto it: sequence){
        cout << it << " ";
    }
    cout << endl;
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