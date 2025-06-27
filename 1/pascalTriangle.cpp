#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

// Type 1: Given row and column, tell the element at that place
    // solution: (n-1) C (r-1) ~ n C r = n! / {r! * (n-r)!} has more time complexity. So, try to reduce its complexity by using maths
// Type 2: Print nth row of the pascal triangle
    // solution: nth row has n elements. So, find n C r for all n elements => TC - O(n * r) 
// Type 3: Given n, print the entire triangle

long long type1(int n, int r){
    // use long long to avoid overflow
    long long res = 1;
    for(int i=0;i<r;i++){
        res = res * (n-i);
        res = res / (i+1);
    }
    return res;
}

void print(vll &ans){
    for(auto it: ans){
        cout << it << " ";
    }
    cout << endl;
}

// TC - O(n)
// SC - O(1)
void type2(int n, vll &ans){
    long long res = 1;
    ans.push_back(res);
    for(int i=1;i<n;i++){
        res = res * (n-i);
        res = res / i;
        ans.push_back(res);
    }
}

vi generateRow(int row){
    long long res = 1;
    vi ansRow;
    ansRow.push_back(res);
    for(int col = 1;col<row;col++){
        res = res * (row - col);
        res = res / col;
        ansRow.push_back(res);
    }
    return ansRow;
}

// TC - O(n^2)
// SC - O()
void type3(int n, vvi &ans2){
    for(int row = 1;row<=n;row++){
        ans2.push_back(generateRow(row));
    }
}

void solve() {
    int r = 5;
    int c = 3;
    cout << "Type 1: " << endl;
    long long res = type1(r-1, c-1);
    cout << "Given row: " << r << " and col: " << c << " pascal value is: " << res << endl << endl;

    cout << "Type 2: " << endl;
    int n = 6;
    vll ans;
    type2(n, ans);
    cout << n << "'th row in pascal triangle is : ";
    print(ans);
    cout << endl;

    cout << "Type 3: " << endl;
    n = 6;
    vvi ans2;
    type3(n, ans2);
    cout << "pascal triangle for n=" << n << " is : " << endl;
    for(auto it: ans2){
        for(auto i: it){
            cout << i << " ";
        }
        cout << endl;
    }
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