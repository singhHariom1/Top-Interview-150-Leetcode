#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 🟠 Approach 1: Brute Force (Rotate One Step k Times)
// Idea: For each rotation, move last node to front.
// Time Complexity: O(n * k)
// Space Complexity: O(1)
class Solution_BruteForce {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Find length of list
        int n = 0;
        ListNode* lenPtr = head;
        while (lenPtr) {
            n++;
            lenPtr = lenPtr->next;
        }

        k = k % n; // reduce unnecessary rotations
        if (k == 0) return head;

        for (int i = 0; i < k; i++) {
            ListNode* temp = head;
            while (temp->next->next) {
                temp = temp->next;
            }
            temp->next->next = head; // last node points to old head
            head = temp->next;       // last node becomes new head
            temp->next = nullptr;    // break link
        }
        return head;
    }
};

// 🟡 Approach 2: Array-based
// Idea: Copy nodes into array, rotate using (i + k) % n, rebuild list.
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution_ArrayBased {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        vector<int> arr;
        ListNode* temp = head;
        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int n = arr.size();
        k = k % n;
        if (k == 0) return head;

        vector<int> rotatedArr;
        // take last k elements
        for (int i = n - k; i < n; i++) {
            rotatedArr.push_back(arr[i]);
        }
        // then first n-k elements
        for (int i = 0; i < n - k; i++) {
            rotatedArr.push_back(arr[i]);
        }

        // rebuild list
        ListNode* dummy = new ListNode(-1);
        temp = dummy;
        for (int val : rotatedArr) {
            temp->next = new ListNode(val);
            temp = temp->next;
        }
        return dummy->next;
    }
};

// 🟢 Approach 3: Optimal (Circular Linked List Trick)
// Idea: Connect tail->next = head (circle), then break at (n-k)th node.
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution_Optimal {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: find length and tail
        int n = 1;
        ListNode* tail = head;
        while (tail->next) {
            n++;
            tail = tail->next;
        }

        // Step 2: make it circular
        tail->next = head;

        // Step 3: find new head position
        k = k % n;
        int stepsToNewHead = n - k;

        // Step 4: move to new tail
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewHead; i++) {
            newTail = newTail->next;
        }

        // Step 5: break circle
        head = newTail->next;
        newTail->next = nullptr;

        return head;
    }
};
