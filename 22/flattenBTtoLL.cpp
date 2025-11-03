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

// TC - O(n)
// SC - O(n)
void flattenBT(TreeNode *root, TreeNode *&prev){
    if (!root)
        return;
    flattenBT(root->right, prev);
    flattenBT(root->left, prev);
    root->right = prev;
    root->left = NULL;
    prev = root;
}

// TC - O(n)
// SC - O(1)
void flattenBToptimal(TreeNode* root){
    TreeNode* curr = root;
    while(curr){
        if(curr->left){
            TreeNode* prev = curr->left;
            while(prev->right){
                prev = prev->right;
            }
            prev->right = curr->right;
            curr->right = curr->left;
        }
        curr = curr->right;
    }
}

void solve()
{
    auto start = chrono::high_resolution_clock::now();

    // Example usage:
    vector<int> arr = {1, 2, 5, 3, 4, -1, 6, -1, -1, -1, -1, -1, -1, 7, -1};
    TreeNode *root = buildTree(arr);
    TreeNode *prev = NULL;
    cout << "Brute Approach: " << endl;
    flattenBT(root, prev);
    while (root)
    {
        cout << root->val << "->";
        root = root->right;
    }
    cout << endl;
    
    cout << "Optimal Approach: " << endl;
    root = buildTree(arr);
    flattenBToptimal(root);
    while (root)
    {
        cout << root->val << "->";
        root = root->right;
    }

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