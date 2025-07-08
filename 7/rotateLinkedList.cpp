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

ListNode *rotateRight(ListNode *head, int k)
{
    if (!head || !head->next || !k)
        return head;

    // count number of nodes
    ListNode *curr = head;
    int cnt = 1;
    while (curr->next)
    {
        curr = curr->next;
        cnt++;
    }

    // point last node to head
    curr->next = head;
    k = k % cnt;
    k = cnt - k;
    // move curr to the node which will be the last node of resultant list
    while (k--)
    {
        curr = curr->next;
    }
    head = curr->next;
    curr->next = NULL;

    return head;
}

void solve()
{
    vi list = {1, 2, 3, 4, 5};
    ListNode *head = createList(list);
    printList(head);
    int k = 2;
    head = rotateRight(head, k);
    printList(head);
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