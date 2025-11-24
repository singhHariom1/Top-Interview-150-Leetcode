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

// 🔴 Approach 1: Recursive with Linear Search
// Time Complexity: O(n^2) - worst case (skewed tree)
// Space Complexity: O(n)
class Solution {
public:
    int preIndex = 0;

    int search(vector<int>& inorder, int start, int end, int value) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == value) return i;
        }
        return -1;
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        int currVal = preorder[preIndex++];
        TreeNode* node = new TreeNode(currVal);

        if (inStart == inEnd) return node;

        int inIndex = search(inorder, inStart, inEnd, currVal);

        node->left = build(preorder, inorder, inStart, inIndex - 1);
        node->right = build(preorder, inorder, inIndex + 1, inEnd);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};

// 🟢 Approach 2: Recursive with Hashmap
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution2 {
public:
    unordered_map<int, int> inMap;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        int currVal = preorder[preIndex++];
        TreeNode* node = new TreeNode(currVal);

        if (inStart == inEnd) return node;

        int inIndex = inMap[currVal];

        node->left = build(preorder, inStart, inIndex - 1);
        node->right = build(preorder, inIndex + 1, inEnd);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return build(preorder, 0, inorder.size() - 1);
    }
};
