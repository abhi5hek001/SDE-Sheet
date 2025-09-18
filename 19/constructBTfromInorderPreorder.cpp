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

TreeNode* buildTree(vi &preorder, int prestart, int preend, vi &inorder, int instart, int inend, map<int,int> &inmap) {
    
    if(prestart > preend || instart > inend) return NULL;

    TreeNode* root = new TreeNode(preorder[prestart]);

    int inroot = inmap[root->val];

    int numsleft = inroot - instart;

    root->left = buildTree(preorder, prestart+1, prestart+numsleft, inorder, instart, inroot-1, inmap);

    root->right = buildTree(preorder, prestart+numsleft+1, preend, inorder, inroot+1, inend, inmap);

    return root;
}

TreeNode* constructBTfromInorderPreorder(vi &preorder, vi &inorder){
    map<int, int> inmap;
    for(int i=0;i<inorder.size();i++){
        inmap[inorder[i]] = i;
    }
    TreeNode* root = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inmap);

    return root;
}

void printLevelOrder(TreeNode* root){
    if(!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        while(n--){
            TreeNode* node = q.front(); q.pop();
            cout << node->val << " ";
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        cout << "\n"; // new line for each level
    }
}

void solve() {
    auto start = chrono::high_resolution_clock::now();

    // Example usage:
    vector<int> preorder = {1, 2, 5, 6, 3, 4, 7};
    vector<int> inorder = {5, 2, 6, 1, 3, 7, 4};

    TreeNode* root = constructBTfromInorderPreorder(preorder, inorder);  
    
    printLevelOrder(root);

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