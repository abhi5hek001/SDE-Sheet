#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, value;
    Node *prev, *next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache; // key -> Node*
    Node *head, *tail; // dummy head & tail

    void addNode(Node* node) {
        // Insert node right after head
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }

    Node* removeTail() {
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        Node* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addNode(newNode);
            if ((int)cache.size() > capacity) {
                Node* tailNode = removeTail();
                cache.erase(tailNode->key);
                delete tailNode;
            }
        }
    }
};

void solve() {
    LRUCache lru(2); // capacity = 2

    lru.put(1, 10); // cache: {1=10}
    lru.put(2, 20); // cache: {2=20, 1=10}

    cout << lru.get(1) << "\n"; // returns 10, cache: {1=10, 2=20}

    lru.put(3, 30); // evicts key 2, cache: {3=30, 1=10}

    cout << lru.get(2) << "\n"; // returns -1
    cout << lru.get(3) << "\n"; // returns 30

    lru.put(4, 40); // evicts key 1, cache: {4=40, 3=30}

    cout << lru.get(1) << "\n"; // returns -1
    cout << lru.get(3) << "\n"; // returns 30
    cout << lru.get(4) << "\n"; // returns 40
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
