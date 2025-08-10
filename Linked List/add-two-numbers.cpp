#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 🟠 Approach 1: Brute Force
// Time Complexity: O(n + m)
// Space Complexity: O(n + m)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long long num1 = 0, num2 = 0, multiplier = 1;
        
        // Convert l1 to number
        multiplier = 1;
        while (l1) {
            num1 += l1->val * multiplier;
            multiplier *= 10;
            l1 = l1->next;
        }
        
        // Convert l2 to number
        multiplier = 1;
        while (l2) {
            num2 += l2->val * multiplier;
            multiplier *= 10;
            l2 = l2->next;
        }
        
        long long sum = num1 + num2;
        
        // Convert sum back to linked list
        if (sum == 0) return new ListNode(0);
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while (sum > 0) {
            curr->next = new ListNode(sum % 10);
            sum /= 10;
            curr = curr->next;
        }
        
        return dummy->next;
    }
};

// 🟢 Approach 2: Optimal (Digit-by-Digit Addition)
// Time Complexity: O(max(n, m))
// Space Complexity: O(max(n, m))
class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;
        
        while (l1 || l2 || carry) {
            int sum = carry;
            
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }
        
        return dummy->next;
    }
};
