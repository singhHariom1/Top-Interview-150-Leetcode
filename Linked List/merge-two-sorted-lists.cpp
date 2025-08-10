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

// 🟠 Approach 1: Brute Force (Using Array + Sorting)
// Time Complexity: O((n + m) log(n + m))
// Space Complexity: O(n + m)
class Solution_Brute {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> mergedArray;
        
        // Store values from both lists
        while (list1) {
            mergedArray.push_back(list1->val);
            list1 = list1->next;
        }
        while (list2) {
            mergedArray.push_back(list2->val);
            list2 = list2->next;
        }

        if (mergedArray.empty()) return NULL;

        // Sort values
        sort(mergedArray.begin(), mergedArray.end());

        // Build new sorted linked list
        ListNode* head = new ListNode(mergedArray[0]);
        ListNode* temp = head;
        for (int i = 1; i < mergedArray.size(); i++) {
            temp->next = new ListNode(mergedArray[i]);
            temp = temp->next;
        }
        return head;
    }
};

// 🟢 Approach 2: Optimal (Two-Pointer Merge In-Place)
// Time Complexity: O(n + m)
// Space Complexity: O(1)
class Solution_Optimal {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0); // Dummy node to simplify pointer handling
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Attach remaining nodes
        tail->next = (list1) ? list1 : list2;

        return dummy.next;
    }
};

// 🟢 Approach 3: Recursive Merge
// Time Complexity: O(n + m)
// Space Complexity: O(n + m) (due to recursion call stack)
class Solution_Recursive {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

/*
📊 Complexity Summary:
------------------------------------------------
Approach      | Time Complexity  | Space Complexity
------------------------------------------------
Brute Force   | O((n+m) log(n+m)) | O(n+m)
Optimal       | O(n+m)           | O(1)
Recursive     | O(n+m)           | O(n+m) (stack)
------------------------------------------------

🔍 Dry Run Example (Optimal / Recursive):
list1 = [1,2,4]
list2 = [1,3,4]

Step-by-step merge:
dummy -> 1(list1) -> 1(list2) -> 2(list1) -> 3(list2) -> 4(list1) -> 4(list2)
Return dummy.next

Output: [1,1,2,3,4,4]
*/
