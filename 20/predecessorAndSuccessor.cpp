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

TreeNode* buildTree(const vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return nullptr;

    vector<TreeNode*> nodes(arr.size(), nullptr);
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] != -1) nodes[i] = new TreeNode(arr[i]);

    for (int i = 0; i < arr.size(); i++) {
        if (!nodes[i]) continue; // skip null parent
        int left = 2*i + 1, right = 2*i + 2;
        if (left < arr.size() && nodes[left]) nodes[i]->left = nodes[left];
        if (right < arr.size() && nodes[right]) nodes[i]->right = nodes[right];
    }

    return nodes[0];
}

// ***********************************Brute**************************************

// TC - O(2h)
// SC - O(1)
vector<TreeNode *> findPreSuc(TreeNode *root, int key)
{
    TreeNode *succ = NULL;
    TreeNode *pred = NULL;
    TreeNode *temp = root;
    
    while (root != NULL)
    {
        // for predecessor
        if (root->val >= key)
        {
            root = root->left;
        }
        else
        {
            pred = root;
            root = root->right;
        }
    }
    
    root = temp;
    while (root != NULL)
    {
        // for successor
        if (root->val <= key)
        {
            root = root->right;
        }
        else
        {
            succ = root;
            root = root->left;
        }
    }
    
    return {pred, succ};
}

// **********************************************************************************

// TC - O(h)
// SC - O(1)
vector<TreeNode *> findPreSucOptimal(TreeNode *root, int key){
    TreeNode* pred = NULL;
    TreeNode* succ = NULL;
    while(root){
        if(root->val == key){
            // predecessor => right-most node of left subtree
            if(root->left){
                TreeNode* temp = root->left;
                while(temp->right) temp = temp->right;
                pred = temp;
            }
            // successor => left-most node of right subtree
            if(root->right){
                TreeNode* temp = root->right;
                while(temp->left) temp = temp->left;
                succ = temp;
            }
            break;
        }
        else if(root->val < key){
            pred = root;
            root = root->right;
        }
        else {
            succ = root;
            root = root->left;
        }
    }
    
    return {pred, succ};
}

        //   8
        //  / \
        // 1   9
        //  \    \
        //   4    10
        //  /
        // 3

void solve()
{
    auto start = chrono::high_resolution_clock::now();
    
    // Example usage:
    vector<int> arr = {4, 2, 6, 1, 3, 5, 7};
    TreeNode *root = buildTree(arr);
    cout << "Brute " << endl;
    vector<TreeNode*> ans = findPreSuc(root, 6);
    cout << "pred: " << ans[0]->val << " and succ: " << ans[1]->val << endl;
    
    cout << "Optimal " << endl;
    vector<TreeNode*> ans2 = findPreSucOptimal(root, 6);
    cout << "pred: " << ans2[0]->val << " and succ: " << ans2[1]->val << endl;

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