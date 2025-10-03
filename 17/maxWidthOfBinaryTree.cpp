#include <bits/stdc++.h>
using namespace std;

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

// max width of BT => number of nodes in a level between any 2 nodes
// left child is (2*i+1) and right child is (2*i+2) => 0 based indexing
// left child is (2*i) and right child is (2*i+1) => 1 based indexing
// 2*i can overflow the integer at any place - in skew tree probably
// we will follow level order traversal
// TC - O(N)
// SC - O(N)
int maxWidthOfBinaryTree(TreeNode *root)
{
    if (!root)
        return 0;   
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    int maxwidth = 0;

    while (!q.empty())
    {
        int size = q.size();
        // Resets index per level to `0` to prevent overflow and keeps widths correct.
        int mmin = q.front().second;
        int first, last;

        for (int i = 0; i < size; i++)
        {
            int currId = q.front().second - mmin;
            TreeNode *node = q.front().first;
            q.pop();
            if (i == 0)
                first = currId;
            if (i == size - 1)
                last = currId;
            if (node->left)
            {
                q.push({node->left, 2 * currId + 1});
            }
            if (node->right)
            {
                q.push({node->right, 2 * currId + 2});
            }
        }
        maxwidth = max(maxwidth, last - first + 1);
    }
    return maxwidth;
}

void solve()
{
    // Example usage:
    vector<int> arr = {1, 3, 7, 8, -1, -1, 4};
    TreeNode *root = buildTree(arr);

    int maxwidth = maxWidthOfBinaryTree(root);
    cout << "Max Width => " << maxwidth;
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