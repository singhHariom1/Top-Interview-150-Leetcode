#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 🔴 Approach 1: Linear Traversal (Brute Force)
// Time Complexity: O(n)
// Space Complexity: O(log n) - recursion stack
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// 🟢 Approach 2: Binary Search on Tree (Optimal)
// Time Complexity: O(log^2 n)
// Space Complexity: O(log n)
class Solution2 {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int leftHeight = 0, rightHeight = 0;
        TreeNode* l = root;
        TreeNode* r = root;
        
        while(l) {
            leftHeight++;
            l = l->left;
        }
        
        while(r) {
            rightHeight++;
            r = r->right;
        }
        
        if (leftHeight == rightHeight) {
            return pow(2, leftHeight) - 1;
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
