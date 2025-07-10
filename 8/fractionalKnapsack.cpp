#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

struct Item{
    int value;
    int weight;
};

bool comp(Item &val1, Item &val2){
    return (val1.value/val1.weight) > (val2.value/val2.weight);
}

int fractionalKnapsack(vector<Item> &items, int capacity){
    sort(items.begin(), items.end(), comp);
    int totalVal = 0;
    int n = items.size();
    for(int i=0;i<n;i++){
        if(items[i].weight <= capacity){
            totalVal += items[i].value;
            capacity -= items[i].weight;
        }else{
            totalVal += (items[i].value/items[i].weight)*capacity;
            break;
        }
    }
    return totalVal;
}

void print(vector<Item> &items){
    for (int i = 0; i < items.size(); ++i) {
        cout << "Item " << i + 1 << ": Value = " << items[i].value
             << ", Weight = " << items[i].weight << "\n";
    }
}

void solve() {
    vector<Item> items;
    
    items.push_back({100,20});
    items.push_back({60,10});
    items.push_back({100,50});
    items.push_back({200,50});

    print(items);
    
    cout << fractionalKnapsack(items, 90) << endl;
    
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