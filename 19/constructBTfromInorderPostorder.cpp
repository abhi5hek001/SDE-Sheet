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

TreeNode* buildTree(vi &postorder, int poststart, int postend, vi &inorder, int instart, int inend, map<int,int> &inmap) {
    
    if(poststart > postend || instart > inend) return NULL;

    TreeNode* root = new TreeNode(postorder[postend]);

    int inroot = inmap[root->val];
    int numsleft = inroot - instart;

    root->left = buildTree(postorder, poststart, poststart + numsleft - 1, inorder, instart, inroot-1, inmap);

    root->right = buildTree(postorder, poststart+numsleft, postend - 1, inorder, inroot+1, inend, inmap);

    return root;
}

TreeNode* constructBTfromInorderPostorder(vi &postorder, vi &inorder){
    map<int, int> inmap;
    for(int i=0;i<inorder.size();i++){
        inmap[inorder[i]] = i;
    }
    TreeNode* root = buildTree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inmap);

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
    vector<int> postorder = {5, 6, 2, 7, 4, 3, 1};
    vector<int> inorder = {5, 2, 6, 1, 3, 7, 4};

    TreeNode* root = constructBTfromInorderPostorder(postorder, inorder);  
    
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