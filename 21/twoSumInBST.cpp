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
// Brute Approach 
// convert it into inorder traversal. then, doing two pointer approach for finding twoSum
// TC - O(2n)
// SC - O(n)

// Better Approach
// Use bstIterator with next() and prev()
// TC - O(N)
// SC - O(H*2)
class BSTIterator {
    stack<TreeNode*> st;
    bool reverse;
private:
    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            if(!reverse){
                node = node->left;
            } else {
                node = node->right;
            }
        }
    }

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root); 
    }

    bool hasNext() {
        return !st.empty();
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();
        if(!reverse){
            pushAll(temp->right);
        } else {
            pushAll(temp->left);
        }
        return temp->val;
    }
};

bool twoSum(TreeNode* root, int k){
    if(!root) return false;
    BSTIterator l(root, false);
    BSTIterator r(root, true);

    int i = l.next();
    int j = r.next();
    while(i < j){
        if(i + j == k) return true;
        else if( i + j < k) i = l.next();
        else j = r.next();
    }
    return false;
}

void solve() {
    auto start = chrono::high_resolution_clock::now();

    // Example usage:
    vector<int> values = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    TreeNode* root = buildBST(values);
    cout << twoSum(root, 10);

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