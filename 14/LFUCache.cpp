#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvl = vector<vll>;
using vvi = vector<vi>;

struct Node {
    int key, value, freq;
    Node *prev, *next;
    Node(int k, int v) : key(k), value(v), freq(1), prev(nullptr), next(nullptr) {}
};

struct DLList {
    Node *head, *tail;
    int size;
    DLList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }
    Node* removeLast() {
        if (size == 0) return nullptr;
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }
};

class LFUCache {
private:
    int capacity, currSize, minFreq;
    unordered_map<int, Node*> nodeMap;          // key -> Node*
    unordered_map<int, DLList*> freqMap;        // freq -> DLList*
    
    void updateFreq(Node* node) {
        int freq = node->freq;
        freqMap[freq]->removeNode(node);
        if (freq == minFreq && freqMap[freq]->size == 0) {
            minFreq++;
        }
        node->freq++;
        if (freqMap.find(node->freq) == freqMap.end()) {
            freqMap[node->freq] = new DLList();
        }
        freqMap[node->freq]->addFront(node);
    }
    
public:
    LFUCache(int cap) {
        capacity = cap;
        currSize = 0;
        minFreq = 0;
    }
    
    int get(int key) {
        if (nodeMap.find(key) == nodeMap.end()) return -1;
        Node* node = nodeMap[key];
        updateFreq(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        
        if (nodeMap.find(key) != nodeMap.end()) {
            Node* node = nodeMap[key];
            node->value = value;
            updateFreq(node);
        } else {
            if (currSize == capacity) {
                Node* nodeToRemove = freqMap[minFreq]->removeLast();
                nodeMap.erase(nodeToRemove->key);
                delete nodeToRemove;
                currSize--;
            }
            Node* newNode = new Node(key, value);
            minFreq = 1;
            if (freqMap.find(minFreq) == freqMap.end()) {
                freqMap[minFreq] = new DLList();
            }
            freqMap[minFreq]->addFront(newNode);
            nodeMap[key] = newNode;
            currSize++;
        }
    }
};

void solve() {
    LFUCache cache(2); // capacity = 2

    cache.put(1, 10); // cache = {1=10}
    cache.put(2, 20); // cache = {1=10, 2=20}

    cout << cache.get(1) << "\n"; // returns 10 (freq of key 1 becomes 2)

    cache.put(3, 30); // evicts key 2 (freq=1 is least), cache = {1=10, 3=30}

    cout << cache.get(2) << "\n"; // returns -1 (not found)
    cout << cache.get(3) << "\n"; // returns 30
    cout << cache.get(1) << "\n"; // returns 10

    cache.put(4, 40); // evicts key 3 (freq=1 is least), cache = {1=10, 4=40}

    cout << cache.get(3) << "\n"; // returns -1
    cout << cache.get(4) << "\n"; // returns 40
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
