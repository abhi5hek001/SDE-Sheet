#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

struct Data{
    int start;
    int end;
    int position;
};

bool comp(Data val1, Data val2){
    // return true only for this - sort according to end time of meeting
    return val1.end < val2.end;
}

// using struct
vi NmeetingsInOneRoom(vi start, vi end){
    int n = start.size();
    Data nums[n];
    for(int i=0;i<n;i++){
        nums[i].start = start[i];
        nums[i].end = end[i];
        nums[i].position = i + 1;
    }
    
    // sort on basis of end time
    sort(nums, nums + n, comp);
    
    int cnt = 1;
    int freetime = nums[0].end;
    vi ds;
    ds.push_back(nums[0].position);
    for(int i=1;i<n;i++){
        if(nums[i].start > freetime){
            cnt += 1;
            freetime = nums[i].end;
            ds.push_back(nums[i].position);
        }
    }
    return ds;
}

// without using struct
vi NmeetingsInOneRoomWithoutStruct(vi start, vi end){
    // {end, start, position}
    vector<tuple<int, int, int>> meetings;
    int n = start.size();
    for(int i=0;i<n;i++){
        meetings.push_back({end[i], start[i], i+1});
    }

    sort(meetings.begin(), meetings.end());

    vi ds;
    int freetime = get<0>(meetings[0]);
    ds.push_back(get<2>(meetings[0]));

    for(int i=1;i<n;i++){
        int e = get<0>(meetings[i]);
        int s = get<1>(meetings[i]);
        int p = get<2>(meetings[i]);

        if(s > freetime){
            ds.push_back(p);
            freetime = e;
        }
    }
    return ds;
}

void solve() {
    vi start = {0,3,1,5,5,8};
    vi end = {5,4,2,9,7,9};
    vi ans = NmeetingsInOneRoom(start, end);
    for(auto it: ans)   
        cout << it << " ";  
    cout << endl;
    cout << "N Meetings: " << ans.size() << endl;
    
    vi ans2 = NmeetingsInOneRoomWithoutStruct(start, end);
    for(auto it: ans)   
        cout << it << " ";  
    cout << endl;
    cout << "(without struct) N Meetings: " << ans.size() << endl;
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