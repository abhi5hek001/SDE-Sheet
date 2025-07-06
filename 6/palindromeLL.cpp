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

// Important TC-O(n) & SC-O(n)
ListNode* reverseLL(ListNode* head){
    if(head==nullptr || head->next==nullptr) return head;

    ListNode* newHead = reverseLL(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

bool checkPalindromeLL(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next!=nullptr && fast->next->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }

    slow->next = reverseLL(slow->next);
    slow=slow->next;

    while(slow!=nullptr){
        if(head->val!=slow->val) return false;

        slow=slow->next;
        head=head->next;
    }
    return true;
}

void solve() {
    vi list = {1,2,3,2,1};
    ListNode* head = createList(list);
    printList(head);

    cout << checkPalindromeLL(head) << endl;
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