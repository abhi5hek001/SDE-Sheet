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

TreeNode *buildTree(const vector<int> &arr)
{
    if (arr.empty())
        return nullptr;
    vector<TreeNode *> nodes(arr.size(), nullptr);
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != -1)
            nodes[i] = new TreeNode(arr[i]);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (nodes[i])
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < arr.size())
                nodes[i]->left = nodes[left];
            if (right < arr.size())
                nodes[i]->right = nodes[right];
        }
    }
    return nodes[0];
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
    TreeNode *root = buildTree(arr);

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