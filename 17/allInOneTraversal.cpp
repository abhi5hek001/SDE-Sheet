#include <bits/stdc++.h>
using namespace std;

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

// TC - O(3N)
// SC - O(4N)
void allInOneTraversal(TreeNode* root, vi &inorder, vi &preorder, vi &postorder){
    stack<pair<TreeNode*, int>> st; // {node, times it arrived}
    st.push({root, 1});
    while(!st.empty()){
        auto it = st.top();
        st.pop();

        if(it.second == 1){
            preorder.push_back(it.first->val);
            it.second++;
            st.push(it);

            if(it.first->left){
                st.push({it.first->left, 1});
            }
        }
        else if(it.second == 2){
            inorder.push_back(it.first->val);
            it.second++;
            st.push(it);

            if(it.first->right){
                st.push({it.first->right, 1});
            }
        }   
        else{
            postorder.push_back(it.first->val);
        }
    }
}

void solve() {
    // Example usage:
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, -1, -1, 8, 9};
    TreeNode* root = buildTree(arr);
    vi inorder;
    vi preorder;
    vi postorder;
    allInOneTraversal(root, inorder, preorder, postorder);
    cout << "Inorder Traversal: ";
    for(auto it: inorder){
        cout << it << " ";
    } cout << endl;
    cout << "Preorder Traversal: ";
    for(auto it: preorder){
        cout << it << " ";
    } cout << endl;
    cout << "Postorder Traversal: ";
    for(auto it: postorder){
        cout << it << " ";
    } cout << endl;
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