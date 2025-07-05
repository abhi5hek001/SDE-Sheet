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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* createList(const vector<int> &vals) {
    if (vals.empty()) return nullptr;
    ListNode *head = new ListNode(vals[0]);
    ListNode *curr = head;
    for (int i = 1; i < vals.size(); ++i) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode *head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

ListNode* removeNthNodeFromBack(ListNode* head, int k){
    ListNode* dNode = new ListNode();
    dNode->next = head;
    ListNode* slow = new ListNode();
    ListNode* fast = new ListNode();
    slow = dNode, fast = dNode;

    int cnt = 0;
    while(fast->next!=nullptr){
        fast = fast->next;
        cnt++;
        if(cnt == k) break;
    }

    while(fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next;
    }
    
    ListNode* node = slow->next;
    slow->next=slow->next->next;
    delete node;

    ListNode* newHead = dNode->next;
    delete dNode;
    return newHead;
}

void solve() {
    vi list = {2,4,1,3,5,6};
    ListNode* head = createList(list);
    printList(head);
    
    int k = 4;
    removeNthNodeFromBack(head, k);
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