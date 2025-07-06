#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createList(const vector<int> &vals)
{
    if (vals.empty())
        return nullptr;
    ListNode *head = new ListNode(vals[0]);
    ListNode *curr = head;
    for (int i = 1; i < vals.size(); ++i)
    {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

ListNode* findIntersectionPointOfYLL(ListNode* l1, ListNode* l2){
    if(l1 == nullptr || l2 == nullptr) return nullptr;

    ListNode* d1 = l1;
    ListNode* d2 = l2;

    while(d1!=d2){
        d1 = (d1 == nullptr) ? l2 : d1->next;
        d2 = (d2 == nullptr) ? l1 : d2->next;
    }

    return d1;
}

void solve()
{
    // Shared part of the Y
    vector<int> shared = {8, 9, 10};
    ListNode *sharedHead = createList(shared);

    // List A: 1 -> 2 -> 3 -> 8 -> 9 -> 10
    vector<int> listA_vals = {1, 2, 3};
    ListNode *listA = createList(listA_vals);
    ListNode *temp = listA;
    while (temp->next)
        temp = temp->next;
    temp->next = sharedHead;

    // List B: 4 -> 5 -> 8 -> 9 -> 10
    vector<int> listB_vals = {4, 5};
    ListNode *listB = createList(listB_vals);
    temp = listB;
    while (temp->next)
        temp = temp->next;
    temp->next = sharedHead;

    // Print both lists
    cout << "List A: ";
    printList(listA);
    cout << "List B: ";
    printList(listB);

    ListNode* intersection = findIntersectionPointOfYLL(listA, listB);
    cout << "Intersection Node: " << intersection->val << endl;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}