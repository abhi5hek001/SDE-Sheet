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

// vvi spiralTraversal(TreeNode* root){
//     vector<vector<int>> ans;
//     if(!root) return ans;
//     int flag = 1;
//     queue<TreeNode*> q;
//     q.push(root);
//     while(!q.empty()){
//         int size = q.size();
//         vector<int> level;
//         for(int i=0;i<size;i++){
//             TreeNode* node = q.front();
//             level.push_back(node->val);
//             q.pop();
//             if(node->left){
//                 q.push(node->left);
//             }
//             if(node->right){
//                 q.push(node->right);
//             }
//         }
//         if(flag == 1){
//             ans.push_back(level);
//             flag = -1;
//         } else {
//             reverse(level.begin(), level.end());
//             ans.push_back(level);
//             flag = 1;
//         }
//     }
//     return ans;
// }

// Optimal way
// TC - O(N)
// SC - O(N)
vvi spiralTraversal(TreeNode* root){
    vector<vector<int>> ans;
    if(!root) return ans;
    bool flag = true;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level(size);
        for(int i=0;i<size;i++){
            TreeNode* node = q.front();
            int index = flag ? i : (size-1) -i;
            level[index] = node->val;
            q.pop();
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        flag = !flag;
        ans.push_back(level);
    }
    return ans;
}

void solve() {
    // Example usage:
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    TreeNode* root = buildTree(arr);
    vvi ans = spiralTraversal(root);

    for(auto it: ans){
        for(auto i: it){
            cout << i << " ";
        } cout << endl;
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