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

bool isLeaf(TreeNode* root){
    if(!root->left && !root->right) return true;
    return false;
}

void leftBoundary(TreeNode* root, vi &ans){
    TreeNode* curr = root->left;
    while(curr){
        if(!isLeaf(curr)) ans.push_back(curr->val);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void leafTraversal(TreeNode* root, vi &ans){
    if(isLeaf(root)){
        ans.push_back(root->val);
        return;
    }
    if(root->left) leafTraversal(root->left, ans);
    if(root->right) leafTraversal(root->right, ans);
}

void rightBoundary(TreeNode* root, vi &ans){
    TreeNode* curr = root->right;
    vi temp;
    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->val);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
    for(int i=temp.size()-1;i>=0;i--){
        ans.push_back(temp[i]);
    }
}

// left boundary excluding leaf nodes + leaf nodes + right boundary [in reverse] excluding leaf nodes
void boundaryTraversalACW(TreeNode* root, vi &ans){
    if(!root) return;

    // adding root to answer
    if(!isLeaf(root)) ans.push_back(root->val);

    leftBoundary(root, ans);
    leafTraversal(root, ans);
    rightBoundary(root, ans);

}

void solve() {
    auto start = chrono::high_resolution_clock::now();

    // Example usage:
    vector<int> arr = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7, 8, -1, -1, 9, 10};
    TreeNode* root = buildTree(arr);
    vi ans;
    boundaryTraversalACW(root, ans);

    for(auto it: ans){
        cout << it << " ";
    } cout << endl;

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    cout << "Time taken: " << duration.count() << " ns\n";
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