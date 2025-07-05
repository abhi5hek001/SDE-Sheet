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

ListNode* add2NumbersAsLinkedList(ListNode* head1, ListNode* head2){
    ListNode* dNode = new ListNode(0);
    int carry = 0;
    ListNode* temp = dNode;
    while(head1!=nullptr || head2!=nullptr || carry){
        int sum = 0;
        if(head1!=nullptr){
            sum += head1->val;
            head1 = head1->next;
        }

        if(head2!=nullptr){
            sum+=head2->val;
            head2 = head2->next;
        }

        sum += carry;
        carry = sum / 10;
        ListNode* newNode = new ListNode(sum%10);
        temp->next = newNode;
        temp = temp->next;
    }
    return dNode->next;
}

void solve()
{
    vi list1 = {2,4,3};
    vi list2 = {5,6,7,9};
    ListNode *head1 = createList(list1);
    ListNode *head2 = createList(list2);
    cout << "list 1" << endl;
    printList(head1);
    cout << "list 2" << endl;
    printList(head2);
    
    cout << "Adding list1 and list2" << endl;
    ListNode* head = add2NumbersAsLinkedList(head1, head2);
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