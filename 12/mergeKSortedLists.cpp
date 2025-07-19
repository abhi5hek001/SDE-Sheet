#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

vector<Node*> buildLinkedLists(const vector<vector<int>>& lists) {
    vector<Node*> heads;

    for (const auto& vec : lists) {
        Node* dummy = new Node(0); // temp dummy node
        Node* curr = dummy;

        for (int val : vec) {
            curr->next = new Node(val);
            curr = curr->next;
        }

        heads.push_back(dummy->next);
        delete dummy; // cleanup
    }

    return heads;
}

void printLinkedLists(Node* temp) {
    while(temp!=nullptr){
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

Node* solveOptimal(vector<Node*>& lists, int k) {
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
    // O(k log K)
    for(int i=0;i<k;i++){
        if (lists[i] != nullptr) {
            // O(log (size of PQ)) ~ O(log K)
            pq.push({lists[i]->val, lists[i]});
        }
    }
    Node* dNode = new Node(-1);
    Node* temp = dNode;
    // O(k * N * 3logK) 
    while(!pq.empty()){
        // min value from minHeap
        // O(logk)
        pair<int, Node*> pr = pq.top();
        Node* node = pr.second;
        temp->next = node;
        // O(logk)
        pq.pop();
        if(node->next){
            // O(logk)
            pq.push({node->next->val, node->next});
        }
        temp = temp->next;
    }
    return dNode->next;
}

void solve() {
    vvi input = {{1,4,5},{1,3,4},{2,6}};
    vector<Node*> lists = buildLinkedLists(input);
    int k = lists.size();
    for(int i=0;i<k;i++){
        printLinkedLists(lists[i]);
        cout << endl;
    } 
    Node* head = solveOptimal(lists, k);
    printLinkedLists(head);
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