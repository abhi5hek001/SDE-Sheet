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
    ListNode *random;
    ListNode() : val(0), next(nullptr), random(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), random(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next), random(random) {}
};

ListNode *createListWithRandom()
{
    // Create 5 nodes
    vector<ListNode *> nodes;
    for (int i = 0; i < 5; ++i)
        nodes.push_back(new ListNode(i + 1));

    // Link next pointers
    for (int i = 0; i < 4; ++i)
        nodes[i]->next = nodes[i + 1];

    // Set some random pointers
    nodes[0]->random = nodes[2]; // 1 -> 3
    nodes[1]->random = nodes[0]; // 2 -> 1
    nodes[2]->random = nodes[4]; // 3 -> 5
    nodes[3]->random = nullptr;  // 4 -> null
    nodes[4]->random = nodes[1]; // 5 -> 2

    return nodes[0]; // head
}

void printListWithRandom(ListNode *head)
{
    while (head)
    {
        cout << "Val: " << head->val;
        if (head->random)
            cout << ", Random: " << head->random->val;
        else
            cout << ", Random: NULL";
        cout << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

ListNode *copyListWithRandomPointer(ListNode *head)
{
    ListNode *temp = head;
    unordered_map<ListNode *, ListNode *> mpp;
    while (temp != NULL)
    {
        ListNode *newNode = new ListNode(temp->val);
        mpp[temp] = newNode;
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        ListNode *copyNode = mpp[temp];
        copyNode->next = mpp[temp->next];
        copyNode->random = mpp[temp->random];
        temp = temp->next;
    }
    return mpp[head];
}

ListNode* copyListWithRandomPointerOptimal(ListNode* head){
    ListNode* temp = head;
    
    while(temp!=nullptr){
        ListNode* copyNode = new ListNode(temp->val);
        copyNode->next = temp->next;
        temp->next = copyNode;
        temp = temp->next->next; 
    }

    temp = head;
    while(temp!=nullptr){
        temp->next->random = temp->random;
        temp = temp->next->next;
    }

    ListNode* dNode = new ListNode(-1);
    ListNode* res = dNode;
    temp = head;
    while(temp!=nullptr){
        res->next = temp->next;
        temp->next = temp->next->next;
        res = res->next;
        temp = temp->next;
    }
    return dNode->next;
}   

void solve()
{
    ListNode *head = createListWithRandom();

    cout << "Original list:\n";
    printListWithRandom(head);

    ListNode *copiedHead = copyListWithRandomPointer(head);
    
    ListNode *copiedHeadOptimal = copyListWithRandomPointerOptimal(head);

    cout << "\nCopied list:\n";
    printListWithRandom(copiedHead);

    cout << "\nOptimal Copied list:\n";
    printListWithRandom(copiedHeadOptimal);
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