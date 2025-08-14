#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

void sortedInsert(stack<int> &stack, int num){
	if(stack.empty() || (!stack.empty() && stack.top() < num)){
		stack.push(num);
		return;
	}
	int n = stack.top();
	stack.pop();

	sortedInsert(stack, num);

	stack.push(n);
}

void sortStack(stack<int> &stack){
	if(stack.empty()) return;

	int num = stack.top();
	stack.pop();

	sortStack(stack);

	sortedInsert(stack, num);
}

void solve() {
    
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