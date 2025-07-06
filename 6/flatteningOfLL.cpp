#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

struct ListNode {
    int val;
    ListNode *next;
    ListNode *bottom;
    ListNode() : val(0), next(nullptr), bottom(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), bottom(nullptr) {}
    ListNode(int x, ListNode *next, ListNode* bottom) : val(x), next(next), bottom(bottom) {}
};

ListNode* createList(const vector<int> &vals) {
    if (vals.empty()) return nullptr;
    ListNode *head = new ListNode(vals[0]);
    ListNode *curr = head;
    for (int i = 1; i < vals.size(); ++i) {
        curr->bottom = new ListNode(vals[i]);
        curr = curr->bottom;
    }
    return head;
}

void printList(ListNode *head) {
    while (head) {
        cout << head->val;
        if (head->bottom) cout << " -> ";
        head = head->bottom;
    }
    cout << endl;
}

ListNode* mergeTwoList(ListNode* l1, ListNode* l2){

    ListNode* temp = new ListNode(0);
    ListNode* res = temp;

    while(l1 != nullptr && l2 != nullptr){
        if(l1->val < l2->val){
            temp->bottom = l1;
            temp = temp->bottom;
            l1 = l1->bottom;
        }
        else{
            temp->bottom = l2;
            temp = temp->bottom;
            l2 = l2->bottom;
        }
    }
    if(l1) temp->bottom = l1;
    else temp->bottom = l2;

    return res->bottom;
}

ListNode* flattenList(ListNode* root){
    
    if(root == nullptr || root->next == nullptr){
        return root;
    }

    root->next = flattenList(root->next);

    root = mergeTwoList(root, root->next);

    return root;
}

void solve() {
    vi l1 = {5,7,8,30};
    vi l2 = {10,20};
    vi l3 = {19,22,50};
    vi l4 = {28,35,40,45};
    ListNode* h1 = createList(l1);
    ListNode* h2 = createList(l2);
    ListNode* h3 = createList(l3);
    ListNode* h4 = createList(l4);

    printList(h1);
    printList(h2);
    printList(h3);
    printList(h4);

    h1->next = h2;
    h2->next = h3;
    h3->next = h4;

    ListNode* head = flattenList(h1);

    cout << "After Flattening all the lists: " << endl;
    printList(head);
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