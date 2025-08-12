#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 🟠 Approach 1: Brute Force (Two Passes + Array)
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution_BruteForce {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // Step 1: Store all values in an array
        vector<int> vals;
        ListNode* temp = head;
        while (temp) {
            vals.push_back(temp->val);
            temp = temp->next;
        }

        // Step 2: Reverse subarray [left-1, right-1]
        reverse(vals.begin() + left - 1, vals.begin() + right);

        // Step 3: Rebuild linked list
        temp = head;
        int idx = 0;
        while (temp) {
            temp->val = vals[idx++];
            temp = temp->next;
        }
        return head;
    }
};

// 🟢 Approach 2: Optimal (One Pass, In-Place)
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution_Optimal {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // Dummy node to handle edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // Step 1: Move prev to node before 'left'
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Step 2: Reverse sublist
        ListNode* curr = prev->next;
        ListNode* nextNode = nullptr;
        ListNode* prevNode = nullptr;

        for (int i = 0; i <= right - left; i++) {
            nextNode = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = nextNode;
        }

        // Step 3: Reconnect reversed sublist back to main list
        prev->next->next = curr;  // tail of reversed part points to remaining list
        prev->next = prevNode;    // prev points to new head of reversed part

        return dummy->next;
    }
};
