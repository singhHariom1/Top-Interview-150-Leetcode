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

// 🟠 Approach 1: Brute Force with Hash Map
// Time: O(n), Space: O(n)
class Solution1 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int, int> freq;
        ListNode* temp = head;
        while (temp) {
            freq[temp->val]++;
            temp = temp->next;
        }
        ListNode dummy(0);
        ListNode* tail = &dummy;
        temp = head;
        while (temp) {
            if (freq[temp->val] == 1) {
                tail->next = temp;
                tail = tail->next;
            }
            temp = temp->next;
        }
        tail->next = nullptr; // important
        return dummy.next;
    }
};

// 🟢 Approach 2: Optimal Two-pointer (Dummy node)
// Time: O(n), Space: O(1)
class Solution2 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (head) {
            if (head->next && head->val == head->next->val) {
                // Skip duplicates
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                prev->next = head->next; // unlink all duplicates
            } else {
                prev = prev->next;
            }
            head = head->next;
        }
        return dummy.next;
    }
};

// 🔵 Approach 3: Recursion
// Time: O(n), Space: O(n) (stack)
class Solution3 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        if (head->val == head->next->val) {
            // Skip entire duplicate block
            while (head->next && head->val == head->next->val) {
                head = head->next;
            }
            return deleteDuplicates(head->next);
        } else {
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }
};
