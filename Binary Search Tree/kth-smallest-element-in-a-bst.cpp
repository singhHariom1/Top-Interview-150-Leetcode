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

// 🟢 Approach: In-order Traversal
// Time Complexity: O(n)
// Space Complexity: O(h)
class Solution {
public:
    int result = -1;
    int count = 0;

    void inOrder(TreeNode* root, int k) {
        if (!root || count >= k) return;
        
        inOrder(root->left, k);
        
        count++;
        if (count == k) {
            result = root->val;
            return;
        }
        
        inOrder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        return result;
    }
};
