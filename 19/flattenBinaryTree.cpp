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

TreeNode* buildTree(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    vector<TreeNode*> nodes(arr.size(), nullptr);
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != -1) nodes[i] = new TreeNode(arr[i]);
    }
    for (int i = 0; i < arr.size(); i++) {
        if (nodes[i]) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < arr.size()) nodes[i]->left = nodes[left];
            if (right < arr.size()) nodes[i]->right = nodes[right];
        }
    }
    return nodes[0];
}

// its kind of reverse postorder - [right left root] 
// Using recursion
// TC - O(N)
// SC - O(N)
void flattenBinaryTree(TreeNode* root, TreeNode* &prev){
    if(!root) return;

    flattenBinaryTree(root->right, prev);
    flattenBinaryTree(root->left, prev);

    root->right = prev;
    root->left = NULL;
    prev = root;
}

// TC - O(N)
// SC - O(1)
void flattenBinaryTreeOptimal(TreeNode* root){
    TreeNode* curr = root;
    while(!curr){
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

void printLevelOrder(TreeNode* root){
    if(!root) return;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        while(n--){
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        cout << "\n";
    }
}

void solve() {
    auto start = chrono::high_resolution_clock::now();

    // Example usage:
    vector<int> arr = {1, 2, 5, 3, 4, -1, 6};
    TreeNode* root = buildTree(arr);
    TreeNode* prev = NULL;

    printLevelOrder(root);
    flattenBinaryTree(root, prev);
    cout << "After flattening Binary Tree:" << endl;
    printLevelOrder(root);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    cout << "\n\nTime taken: " << duration.count() << " ns\n";

    auto start2 = chrono::high_resolution_clock::now();

    // Example usage:
    vector<int> arr2 = {1, 2, 5, 3, 4, -1, 6};
    TreeNode* root2 = buildTree(arr2);

    printLevelOrder(root2);
    flattenBinaryTreeOptimal(root2);
    cout << "After flattening Binary Tree:" << endl;
    printLevelOrder(root2);

    auto stop2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::nanoseconds>(stop2 - start2);
    cout << "\n\nTime taken: " << duration2.count() << " ns\n";
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