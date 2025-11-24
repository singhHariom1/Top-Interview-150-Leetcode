#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 🟢 Approach: Recursive DFS
// Time Complexity: O(n) - We might visit all nodes in the worst case.
// Space Complexity: O(h) - Recursion stack depth is equal to height of the tree.
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if root is null or root is one of p or q, return root
        if (!root || root == p || root == q) {
            return root;
        }

        // Search in left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both left and right return a node, it means p and q are found in different subtrees
        // so root is the LCA
        if (left && right) {
            return root;
        }

        // Otherwise return the non-null child (or null if both are null)
        return left ? left : right;
    }
};
