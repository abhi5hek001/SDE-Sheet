#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    vector<TreeNode*> nodes(arr.size(), nullptr);
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != -1) nodes[i] = new TreeNode(arr[i]);
    }
    for (int i = 0; i < arr.size(); i++) {
        if (nodes[i]) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < arr.size()) nodes[i]->left = nodes[left];
            if (right < arr.size()) nodes[i]->right = nodes[right];
        }
    }
    return nodes[0];
}

int height(TreeNode* root){
    if(!root) return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + max(lh, rh);
}

// Diameter is the longest path between any 2 nodes
// path need not to pass from root
// diameter is max(lh + rh) considering that node as curve point
// TC - O(N^2)
void diameterofBT(TreeNode* root, int &maxi){
    if(!root) return;

    int lh = height(root->left);
    int rh = height(root->right);

    maxi = max(maxi, lh+rh);

    diameterofBT(root->left, maxi);
    diameterofBT(root->right, maxi);
}

// Optimal Approach => TC - O(N)
int diameterofBToptimal(TreeNode* root, int &maxi){
    if(!root) return 0;

    int lh = height(root->left);
    int rh = height(root->right);
    maxi = max(maxi, lh+rh);
    return 1 + max(lh, rh);
}

void solve() {
    vector<int> arr = {1, 2, 3, -1, 5};
    TreeNode* root = buildTree(arr);

    int maxi = INT_MIN;

    // ---------------- O(N^2) approach ----------------
    auto start1 = chrono::high_resolution_clock::now();
    diameterofBT(root, maxi);
    auto stop1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::nanoseconds>(stop1 - start1);

    cout << "Diameter is: " << maxi << "\n";
    cout << "Time (O(N^2) approach): " << duration1.count() << " ns\n\n";

    // ---------------- O(N) approach ----------------
    maxi = INT_MIN;
    auto start2 = chrono::high_resolution_clock::now();
    diameterofBToptimal(root, maxi);
    auto stop2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::nanoseconds>(stop2 - start2);

    cout << "(Optimal Approach) Diameter is: " << maxi << "\n";
    cout << "Time (O(N) approach): " << duration2.count() << " ns\n";
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