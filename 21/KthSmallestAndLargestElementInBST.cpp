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

// Insert a value into the BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

// Build BST from a list of values
TreeNode* buildBST(const vector<int>& values) {
    TreeNode* root = nullptr;
    for (int val : values)
        root = insertBST(root, val);
    return root;
}

// first store all nodes in a vector, then sort it and find answer
// TC - O(n) + O(n logn)
// SC - O(n)

// Better Approach
// find the inorder of BST that will be automatically sorted
// TC - O(n)
// SC - O(n)

// Optimal Approach
// inorder approach with the counter to avoid storing inorder traversal
// TC - O(n)
// SC - O(1)
void KthSmallestElemInBST(TreeNode* root, int &cnt, int k){
    if(!root) return;
    KthSmallestElemInBST(root->left, cnt, k);
    cnt++;
    if(cnt == k){
        cout << "Kth smallest element in BST is: " << root->val << " ";
    }
    KthSmallestElemInBST(root->right, cnt, k);
}

// for KthLargestElementInBST, find number of nodes by doing one traversal
// then find for (n-k)th smallestElementInBST
// kth largest = (n-k)th smallest
int countNodes(TreeNode* root){
    if(!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void KthLargestElemInBST(TreeNode* root, int &cnt, int k){
    if(!root) return;
    KthLargestElemInBST(root->left, cnt, k);
    cnt++;
    if(cnt == k){
        cout << "Kth largest element in BST is: " << root->val << " ";
    }
    KthLargestElemInBST(root->right, cnt, k);
}

void solve() {
    auto start = chrono::high_resolution_clock::now();

    // Example usage:
    vector<int> values = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    TreeNode* root = buildBST(values);
    int cnt = 0;
    int k = 6;
    KthSmallestElemInBST(root, cnt, k);
    cout << endl;
    int n = countNodes(root);
    cnt = 0;
    KthLargestElemInBST(root, cnt, n-k);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    cout << "\n\nTime taken: " << duration.count() << " ns\n";
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