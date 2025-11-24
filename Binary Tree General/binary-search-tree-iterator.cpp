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

// 🟢 Approach: Controlled Recursion (Stack)
// Time Complexity: O(1) amortized for next(), O(1) for hasNext()
// Space Complexity: O(h) - Stack stores at most h nodes (height of tree)
class BSTIterator {
private:
    stack<TreeNode*> s;

    void pushAll(TreeNode* node) {
        while (node) {
            s.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* tmpNode = s.top();
        s.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
