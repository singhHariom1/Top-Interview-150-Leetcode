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

// 🟢 Approach: Recursive DFS
// Time Complexity: O(n) - We visit each node once.
// Space Complexity: O(h) - Where h is the height of the tree (recursion stack).
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        calculateMaxPath(root, maxSum);
        return maxSum;
    }

private:
    int calculateMaxPath(TreeNode* node, int& maxSum) {
        if (!node) return 0;

        // Recursively get the max path sum from left and right subtrees
        // If the path sum is negative, we ignore it (take 0)
        int leftMax = max(0, calculateMaxPath(node->left, maxSum));
        int rightMax = max(0, calculateMaxPath(node->right, maxSum));

        // Update the global maximum path sum
        // The path through the current node includes the node itself and the max paths from left and right
        maxSum = max(maxSum, node->val + leftMax + rightMax);

        // Return the max path sum extendable to the parent
        // We can only choose one branch (left or right) to extend to the parent
        return node->val + max(leftMax, rightMax);
    }
};
