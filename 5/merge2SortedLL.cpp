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
    cout << endl;
}

ListNode* merge2SortedLLExtSpace(ListNode* head1, ListNode* head2){
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    
    while(head1!=NULL && head2!=NULL){
        if(head1->val < head2->val){
            temp->next = new ListNode(head1->val);
            head1 = head1->next;
        } else {
            temp->next = new ListNode(head2->val);
            head2 = head2->next;
        }
        temp = temp->next;
    }
    while(head1!=NULL){
        temp->next = new ListNode(head1->val);
        head1 = head1->next;    
    }
    while(head2!=NULL){
        temp->next = new ListNode(head2->val);
        head2 = head2->next;
    }
    return dummy->next;
}

// IMPORTANT
ListNode* merge2SortedLLInSpace(ListNode* head1, ListNode* head2){
    if(head1==nullptr) return head2;
    if(head2==nullptr) return head1;
    
    // smaller value to res
    if(head1->val > head2->val) swap(head1, head2);
    ListNode* res = head1;
    while(head1!=nullptr && head2!=nullptr){
        ListNode* temp = head1;
        while(head1!=NULL && head1->val <= head2->val){
            temp = head1;
            head1 = head1->next;
        }
        temp->next = head2;
        swap(head1, head2);
    }
    return res;
}

void solve() {
    vi list1 = {1,2,4};
    vi list2 = {1,3,4};
    ListNode* head1 = createList(list1);
    ListNode* head2 = createList(list2);
    cout << "LL 1" << endl;
    printList(head1);
    cout << "LL 2" << endl;
    printList(head2);
    
    cout << "Ext Place Merged LL" << endl;
    ListNode* exthead = merge2SortedLLExtSpace(head1, head2);
    
    printList(exthead);
    
    cout << "In Place Merged LL" << endl;
    ListNode* inhead = merge2SortedLLInSpace(head1, head2);
    
    printList(inhead);
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