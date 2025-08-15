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

// 🟠 Approach 1: Brute Force (Extra Space)
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution_BruteForce {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: Store values
        vector<int> arr;
        ListNode* temp = head;
        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        // Step 2: Reverse each k-sized block
        int n = arr.size();
        for (int i = 0; i + k <= n; i += k) {
            reverse(arr.begin() + i, arr.begin() + i + k);
        }

        // Step 3: Build new linked list
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        for (int val : arr) {
            tail->next = new ListNode(val);
            tail = tail->next;
        }
        return dummy->next;
    }
};

// 🟢 Approach 2: Optimal Iterative In-place
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution_Optimal {
private:
    // Reverse a linked list segment from head to tail
    pair<ListNode*, ListNode*> reverseSegment(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* curr = head;
        while (prev != tail) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return {tail, head};
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* groupPrev = &dummy;

        while (true) {
            // Find kth node
            ListNode* kth = groupPrev;
            for (int i = 0; i < k && kth; i++) kth = kth->next;
            if (!kth) break;

            ListNode* groupNext = kth->next;
            auto reversed = reverseSegment(groupPrev->next, kth);
            groupPrev->next = reversed.first;
            reversed.second->next = groupNext;

            groupPrev = reversed.second;
        }
        return dummy.next;
    }
};

// 🌀 Approach 3: Recursive In-place
// Time Complexity: O(n)
// Space Complexity: O(n/k) recursion stack
class Solution_Recursive {
private:
    // Helper to reverse a segment [head, tail]
    pair<ListNode*, ListNode*> reverseSegment(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* curr = head;
        while (prev != tail) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return {tail, head};
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: Find kth node
        ListNode* kth = head;
        for (int i = 0; i < k && kth; i++) kth = kth->next;
        if (!kth) return head; // Less than k nodes remain

        // Step 2: Reverse current group
        ListNode* tail = head;
        for (int i = 1; i < k; i++) tail = tail->next;
        auto reversed = reverseSegment(head, tail);

        // Step 3: Recursively reverse the rest
        reversed.second->next = reverseKGroup(tail->next, k);

        return reversed.first;
    }
};
