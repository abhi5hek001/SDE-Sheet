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
    TreeNode* next;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
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

// next node in level order traversal

// For tree [1,2,3,4,5,6,7]:
// Queue starts: [1, NULL]
// Pop 1, connect nothing (since prev=NULL). Push its children 2,3.
// Queue = [NULL, 2, 3], prev=1.
// Pop NULL → level ends. Push new NULL.
// Queue = [2,3,NULL], prev=NULL.
// Pop 2. Push 4,5. Connect nothing (since prev=NULL).
// Queue = [3,NULL,4,5], prev=2.
// Pop 3. Push 6,7. Connect prev(2)->next=3.
// Queue = [NULL,4,5,6,7], prev=3.
// Pop NULL → end of level. Push new NULL.
// Queue = [4,5,6,7,NULL], prev=NULL.
// Pop 4. Push nothing. prev=NULL.
// Queue = [5,6,7,NULL], prev=4
// Pop 5. Connect 4->next=5. Push nothing.
// Queue = [6,7,NULL], prev=5.
// Pop 6. Connect 5->next=6.
// Queue = [7,NULL], prev=6.
// Pop 7. Connect 6->next=7.
// Queue = [NULL], prev=7
// Pop NULL. Queue empty → done.
// TC - O(n)
// SC - O(n)
TreeNode* populateNextRightPointer(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    TreeNode* prev = NULL;

    while(q.size()){
        TreeNode* curr = q.front();
        q.pop();
        
        if(curr == NULL){
            if(q.size() == 0) break;
            q.push(NULL);
        } else {
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
            if(prev != NULL){
                prev->next = curr;
            }
        }
        prev = curr;
    }
    return root;
}

void print(TreeNode* root) {
    if (!root) return;

    TreeNode* level = root;

    while (level) {
        TreeNode* curr = level;
        while (curr) {
            cout << curr->val << " ";
            curr = curr->next;   // move along the level
        }
        cout << "# ";            // end of this level
        level = level->left;     // move to next level
    }
}

// TC - O(n)
// SC - O(1)
TreeNode* populateNextRightPointerOptimal(TreeNode* root){
    if(!root) return root;

    if(root->left) 
        root->left->next = root->right;

    if(root->right && root->next)
        root->right->next = root->next->left;
    
    populateNextRightPointerOptimal(root->left);
    populateNextRightPointerOptimal(root->right);

    return root;
}

void solve() {
    auto start = chrono::high_resolution_clock::now();

    // Example usage:
    vector<int> arr = {1,2,3,4,5,6,7};
    TreeNode* root = buildTree(arr);
    cout << "Better Approach" << endl;
    root = populateNextRightPointer(root);
    print(root);
    cout << endl;
    
    root = buildTree(arr);
    cout << "Optimal Approach" << endl;
    root = populateNextRightPointerOptimal(root);
    print(root);

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