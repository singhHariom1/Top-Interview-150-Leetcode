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

// 🟠 Approach 1: Brute Force (2-pass traversal)
// 1. Find length of the list.
// 2. Identify (length - n + 1)-th node from the start.
// 3. Remove it with pointer manipulation.
// Time Complexity: O(L)
// Space Complexity: O(1)
class SolutionBruteForce {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int length = 0;
        while (temp) {
            length++;
            temp = temp->next;
        }

        // Case: removing the head node
        if (n == length) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Traverse to the node before the one we need to remove
        temp = head;
        for (int i = 1; i < length - n; i++) {
            temp = temp->next;
        }

        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        return head;
    }
};


// 🟢 Approach 2: Optimal (One-pass with Two Pointers)
// 1. Use a dummy node before head (simplifies edge cases).
// 2. Move `fast` pointer n+1 steps ahead.
// 3. Move `slow` and `fast` together until `fast` reaches null.
// 4. Now `slow->next` is the target node. Remove it.
// Time Complexity: O(L)
// Space Complexity: O(1)
class SolutionOptimal {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast ahead by n+1 steps
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches end
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove node
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        ListNode* newHead = dummy->next;
        delete dummy; // free dummy node
        return newHead;
    }
};


// 🟡 Approach 3: Recursion
// 1. Recurse to the end of the list.
// 2. Count nodes backwards as recursion unwinds.
// 3. Skip the nth node by adjusting pointers.
// Time Complexity: O(L)
// Space Complexity: O(L) due to recursion stack
class SolutionRecursive {
private:
    int dfs(ListNode* node, int n, ListNode*& head) {
        if (!node) return 0;
        int count = dfs(node->next, n, head) + 1;
        if (count == n + 1) {
            ListNode* toDelete = node->next;
            node->next = node->next->next;
            delete toDelete;
        }
        if (count == n && node == head) {
            // Special case: head needs to be removed
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
        }
        return count;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        dfs(head, n, head);
        return head;
    }
};
