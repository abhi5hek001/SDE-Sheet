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

TreeNode* findFloor(TreeNode* root, int key){
    TreeNode* floor;
    while(root){
        if(root->val == key){
            floor = root;
            return floor;
        }
        if(root->val > key){
            root = root->left;
        }
        else {
            floor = root;
            root = root->right;
        }
    }
    return floor;
}

void solve() {
    auto start = chrono::high_resolution_clock::now();

    // Example usage:
    vector<int> arr = {10,5,15,2,8,13,17,-1,-1,6};
    TreeNode* root = buildBST(arr);
    TreeNode* floor = findFloor(root, 9);
    cout << "Floor is: " << floor->val << endl;

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