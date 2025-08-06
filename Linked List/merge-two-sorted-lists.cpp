#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 🟠 Approach 1: Brute Force
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution_Brute {
public:
    ListNode* middleNode(ListNode* head) {
        int length = 0;
        ListNode* temp = head;

        // First pass: find length
        while (temp) {
            length++;
            temp = temp->next;
        }

        // Second pass: reach middle
        temp = head;
        for (int i = 0; i < length / 2; i++) {
            temp = temp->next;
        }

        return temp;
    }
};

// 🟢 Approach 2: Optimal (Slow & Fast Pointers)
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution_Optimal {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
