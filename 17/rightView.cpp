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

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// TC - O(N)
// SC - O(H)
// Reversed Preorder traversal - NRL
void rightView(TreeNode* node, int level, vector<TreeNode*> &ds){
    if(node == nullptr) return;

    if(level == ds.size()) ds.push_back(node);
    rightView(node->right, level+1, ds);
    rightView(node->left, level+1, ds);
}

void solve() {
    // Example usage:
    vector<int> arr = {1,2,3,4,5,-1,7,-1,-1,6};
    TreeNode* root = buildTree(arr);
    vector<TreeNode*> ds;
    rightView(root, 0, ds);
    for(auto it: ds){
        cout << it->val << " ";
    } cout << endl;
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