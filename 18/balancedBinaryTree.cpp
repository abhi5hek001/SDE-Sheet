#include <bits/stdc++.h>
using namespace std;
#include <chrono>

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

// balanced BT - for every node, [height(left) - height(right) <= 1]
// TC - O(N^2)
bool balancedBinaryTree(TreeNode* root){
    if(!root) return true;

    int lh = height(root->left);
    int rh = height(root->right);
 
    if(abs(rh - lh) > 1) return false;

    bool left = balancedBinaryTree(root->left);
    bool right = balancedBinaryTree(root->right);

    if(!left || !right) return false;

    return true;
}

// TC - O(N)
int balancedBinaryTreeOptimal(TreeNode* root){
    if(!root) return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    if(lh == -1 || rh == -1) return -1;
    if(abs(rh - lh) > 1) return -1;

    return 1 + max(lh, rh);
}

void solve() {
    auto start = chrono::high_resolution_clock::now();
    
    vector<int> arr = {1, 2, -1, 3, -1, -1, -1, 4};

    TreeNode* root = buildTree(arr);
    int res = balancedBinaryTree(root);
    cout << "Brute Approach" << endl;
    if(res) cout << "It is a balanced Binary Tree" << endl;
    else cout << "It is not a balanced binary tree" << endl;
    
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    cout << "Time taken: " << duration.count() << " ns\n";
    
    cout << endl;

    auto start2 = chrono::high_resolution_clock::now();
    
    int res2 = balancedBinaryTreeOptimal(root);
    cout << "Optimal Approach" << endl;
    if(res2 != -1) cout << "It is a balanced Binary Tree" << endl;
    else cout << "It is not a balanced binary tree" << endl;
    
    auto stop2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::nanoseconds>(stop2 - start2);
    cout << "Time taken: " << duration2.count() << " ns\n";
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