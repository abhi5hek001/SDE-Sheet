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

// ***********************************Brute*******************************************

// TreeNode *buildBST(vector<int> &preorder, int prestart, int preend,
//                    vector<int> &inorder, int instart, int inend, map<int, int> &inmap)
// {
//     if (prestart > preend || instart > inend)
//         return NULL;

//     TreeNode *root = new TreeNode(preorder[prestart]);
//     int inroot = inmap[root->val];
//     int numsleft = inroot - instart;

//     root->left = buildBST(preorder, prestart + 1, prestart + numsleft,
//                           inorder, instart, inroot - 1, inmap);
//     root->right = buildBST(preorder, prestart + numsleft + 1, preend,
//                            inorder, inroot + 1, inend, inmap);
//     return root;
// }

// // In BST, if we sort all the keys => we get inorder
// TreeNode *bstFromPreorder(vector<int> &preorder)
// {
//     vector<int> inorder = preorder;
//     sort(inorder.begin(), inorder.end());
//     map<int, int> inmap;
//     for (int i = 0; i < preorder.size(); i++)
//     {
//         inmap[inorder[i]] = i;
//     }

//     TreeNode *root = buildBST(preorder, 0, preorder.size() - 1,
//                               inorder, 0, inorder.size() - 1, inmap);

//     return root;
// }

// ******************************************************************************

// ***********************************Optimal*****************************************
// TC - O(N)
// SC - O(1)
TreeNode *buildBST(vector<int> &preorder, int &i, long bound)
{
    if (i == preorder.size() || preorder[i] > bound)
    return NULL;
    TreeNode *root = new TreeNode(preorder[i++]);
    root->left = buildBST(preorder, i, root->val);
    root->right = buildBST(preorder, i, bound);
    return root;
}

// here we only keep upper bound
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int i = 0;
    return buildBST(preorder, i, LONG_MAX);
}

// ******************************************************************************

void solve()
{
    auto start = chrono::high_resolution_clock::now();

    // Example usage:
    vector<int> arr = {1, 2, 3, -1, 5};
    TreeNode *root = buildTree(arr);

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