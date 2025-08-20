#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Brute Force
// Idea:
// - Store key-value pairs in a vector.
// - get(key):
//     * Iterate through vector to find key.
//     * If found → move it to the "most recent" end of the vector and return value.
//     * Else return -1.
// - put(key, value):
//     * Iterate through vector to find key. If found → update value and move to end.
//     * Else insert new pair at the end.
//     * If size > capacity → erase the front element (least recent).
// Time Complexity: O(n) per get/put
// Space Complexity: O(capacity)

class LRUCache_BruteForce {
private:
    int capacity;
    vector<pair<int,int>> cache; // {key, value}

public:
    LRUCache_BruteForce(int _capacity) {
        capacity = _capacity;
    }

    int get(int key) {
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i].first == key) {
                int value = cache[i].second;
                // move this pair to end (most recent)
                cache.erase(cache.begin() + i);
                cache.push_back({key, value});
                return value;
            }
        }
        return -1; // not found
    }

    void put(int key, int value) {
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i].first == key) {
                // update and move to end
                cache.erase(cache.begin() + i);
                cache.push_back({key, value});
                return;
            }
        }
        // new key
        cache.push_back({key, value});
        if (cache.size() > capacity) {
            cache.erase(cache.begin()); // evict least recent
        }
    }
};


// 🟢 Approach 2: Optimal using Doubly Linked List + HashMap
// Idea:
// - HashMap provides O(1) lookup.
// - Doubly Linked List maintains usage order.
//     * Head = Most Recently Used (MRU).
//     * Tail = Least Recently Used (LRU).
// - get(key): if found → move node to head, return value.
// - put(key, value):
//     * If exists → update + move to head.
//     * Else → insert at head, if over capacity → evict from tail.
// Time Complexity: O(1) per get/put
// Space Complexity: O(capacity)

class Node {
public:
    int key, value;
    Node* prev;
    Node* next;
    Node(int _key, int _value) {
        key = _key;
        value = _value;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> mp; // key -> node
    Node* head; // dummy head
    Node* tail; // dummy tail

    void addNode(Node* node) {
        Node* next = head->next;
        head->next = node;
        node->prev = head;
        node->next = next;
        next->prev = node;
    }

    void removeNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }

    Node* popTail() {
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }

public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1; // not found
        }
        Node* node = mp[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            moveToHead(node);
        } else {
            Node* node = new Node(key, value);
            addNode(node);
            mp[key] = node;

            if ((int)mp.size() > capacity) {
                Node* tailNode = popTail();
                mp.erase(tailNode->key);
                delete tailNode;
            }
        }
    }
};
