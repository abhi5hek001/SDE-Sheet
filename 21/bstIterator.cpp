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

// TC - O(1) => O(N/N) ~ O(1) [pushing node N times and then calling next() N times]
// SC - O(H) [we are going left-left at initialisation approx it is height of bst]
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

void solve() {
    auto start = chrono::high_resolution_clock::now();

    // Example usage:
    vector<int> values = {7, 3, 15, 9, 20};
    TreeNode* root = buildBST(values);
    
    BSTIterator it(root, false);
    
    cout << "Forward:\n";
    if(it.hasNext()) cout << it.next() << "\n";
    if(it.hasNext()) cout << it.next() << "\n";
    if(it.hasNext()) cout << it.next() << "\n";
    if(it.hasNext()) cout << it.next() << "\n";
    
    cout << "\nBackward:\n";
    BSTIterator it2(root, true);
    cout << it2.next() << "\n"; 
    cout << it2.next() << "\n";
    cout << it2.next() << "\n";

    cout << "\nForward again:\n";
    if(it.hasNext()) cout << it.next() << "\n";
    if(it.hasNext()) cout << it.next() << "\n";
    if(it.hasNext()) cout << it.next() << "\n";

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