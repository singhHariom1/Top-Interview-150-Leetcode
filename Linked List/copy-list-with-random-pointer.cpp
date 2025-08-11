#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// 🟠 Approach 1: Brute Force using Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution_BruteForce {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> map;

        // Step 1: Create copies of all nodes and store mapping
        Node* temp = head;
        while (temp) {
            map[temp] = new Node(temp->val);
            temp = temp->next;
        }

        // Step 2: Assign next and random pointers for copied nodes
        temp = head;
        while (temp) {
            Node* copy = map[temp];
            copy->next = map[temp->next];
            copy->random = map[temp->random];
            temp = temp->next;
        }

        return map[head];
    }
};

// 🟢 Approach 2: Optimal O(1) Space using Interleaving Method
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution_Optimal {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* temp = head;

        // Step 1: Insert cloned nodes after original nodes
        while (temp) {
            Node* nextNode = temp->next;
            Node* copy = new Node(temp->val);
            temp->next = copy;
            copy->next = nextNode;
            temp = nextNode;
        }

        // Step 2: Set random pointers for cloned nodes
        temp = head;
        while (temp) {
            if (temp->random) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        // Step 3: Separate the original and cloned lists
        Node* dummy = new Node(0);
        Node* copyTail = dummy;
        temp = head;
        while (temp) {
            Node* copy = temp->next;
            Node* nextNode = copy->next;

            copyTail->next = copy;
            copyTail = copy;

            temp->next = nextNode; // Restore original list
            temp = nextNode;
        }

        return dummy->next;
    }
};
