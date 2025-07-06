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

ListNode* createCycledList(const vector<int> &vals, int pos) {
    if (vals.empty()) return nullptr;

    ListNode *head = new ListNode(vals[0]);
    ListNode *curr = head;
    ListNode *cycleEntry = nullptr;

    for (int i = 1; i < vals.size(); ++i) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
        if (i == pos) {
            cycleEntry = curr;
        }
    }

    if (pos == 0) cycleEntry = head;
    if (cycleEntry) curr->next = cycleEntry;

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

ListNode* startingPointOfCycleInLL(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        // slow & fast collided - cycle exists
        if(slow == fast){
            slow = head;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}

void solve() {
    vector<int> vals = {1,2,3,4,5,6,7,8,9,10};
    int ind = 3;

    ListNode* head = createCycledList(vals, ind);

    cout << startingPointOfCycleInLL(head)->val << endl;
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