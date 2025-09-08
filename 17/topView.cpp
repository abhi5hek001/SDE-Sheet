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
// SC - O(N)
vector<int> topView(TreeNode* root){
    vector<int> ans;
    if(root == nullptr) return ans;
    queue<pair<TreeNode*, int>> q; // {node, line}
    map<int, int> mp; // {line, node->val}
    q.push({root, 0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode* node = it.first;
        int line = it.second;
        if(mp.find(line) == mp.end()){
            mp[line] = node->val;
        }
        if(node->left){
            q.push({node->left, line-1});
        }
        if(node->right){
            q.push({node->right, line+1});
        }
    }
    for(auto it: mp){
        ans.push_back(it.second);
    }
    return ans;
}

void solve() {
    // Example usage:
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, -1, -1, 8, 9};
    TreeNode* root = buildTree(arr);
    vector<int> ans;
    ans = topView(root);
    for(auto it: ans){
        cout << it << " ";
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