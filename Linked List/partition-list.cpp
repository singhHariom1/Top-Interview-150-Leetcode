#include <bits/stdc++.h>
using namespace std;


//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 🟠 Approach 1: Brute Force using Vectors
// - Traverse list twice: first collect < x, then >= x
// - Store them in a vector and rebuild a new linked list
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution_BruteForce {
public:
    ListNode* partition(ListNode* head, int x) {
        vector<int> result;
        ListNode* temp = head;
        while (temp) {
            if (temp->val < x) result.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp) {
            if (temp->val >= x) result.push_back(temp->val);
            temp = temp->next;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        for (int val : result) {
            tail->next = new ListNode(val);
            tail = tail->next;
        }
        return dummy->next;
    }
};

// 🟡 Approach 2: Two Dummy Lists (Optimal)
// - Use two dummy heads for < x and >= x lists
// - Traverse once and append nodes accordingly
// - Finally connect both lists
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution_TwoLists {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode lessDummy(0), greaterDummy(0);
        ListNode* less = &lessDummy;
        ListNode* greater = &greaterDummy;

        while (head) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }
        greater->next = nullptr;
        less->next = greaterDummy.next;
        return lessDummy.next;
    }
};

// 🟢 Approach 3: In-place Rearrangement (Pointer Redirection)
// - Same as Approach 2 but thought of as in-place partitioning
// - No extra nodes created, only pointers rearranged
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution_Optimal {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode beforeHead(0), afterHead(0);
        ListNode* before = &beforeHead;
        ListNode* after = &afterHead;

        while (head) {
            if (head->val < x) {
                before->next = head;
                before = before->next;
            } else {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        after->next = nullptr;
        before->next = afterHead.next;
        return beforeHead.next;
    }
};
