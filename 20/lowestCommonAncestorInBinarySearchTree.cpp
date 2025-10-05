#include <bits/stdc++.h>
using namespace std;
#include <chrono>

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
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

TreeNode *findNode(TreeNode *root, int val)
{
    if (!root)
        return nullptr;
    if (root->val == val)
        return root;
    TreeNode *left = findNode(root->left, val);
    if (left)
        return left;
    return findNode(root->right, val);
}

TreeNode *lowestCommonAncestorInBST(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestorInBST(root->left, p, q);
    else if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestorInBST(root->right, p, q);
    else
        return root; // split happens here
}

    //       6
    //     /   \
    //    2     8
    //   / \   / \
    //  0   4 7   9
    //     / \
    //    3   5

void solve()
{
    auto start = chrono::high_resolution_clock::now();

    // Example usage:
    vector<int> arr = {6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5};
    TreeNode *root = buildBST(arr);

    TreeNode *p = findNode(root, 2);
    TreeNode *q = findNode(root, 5);

    TreeNode *lca = lowestCommonAncestorInBST(root, p, q);
    cout << lca->val;

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    cout << "\n\nTime taken: " << duration.count() << " ns\n";
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}