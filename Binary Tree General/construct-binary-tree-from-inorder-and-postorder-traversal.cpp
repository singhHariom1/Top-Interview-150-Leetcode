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
// Time Complexity: O(n^2) - worst case
// Space Complexity: O(n)
class Solution {
public:
    int postIndex;

    int search(vector<int>& inorder, int start, int end, int value) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == value) return i;
        }
        return -1;
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        int currVal = postorder[postIndex--];
        TreeNode* node = new TreeNode(currVal);

        if (inStart == inEnd) return node;

        int inIndex = search(inorder, inStart, inEnd, currVal);

        node->right = build(inorder, postorder, inIndex + 1, inEnd);
        node->left = build(inorder, postorder, inStart, inIndex - 1);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size() - 1;
        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};

// 🟢 Approach 2: Recursive with Hashmap
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution2 {
public:
    unordered_map<int, int> inMap;
    int postIndex;

    TreeNode* build(vector<int>& postorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        int currVal = postorder[postIndex--];
        TreeNode* node = new TreeNode(currVal);

        if (inStart == inEnd) return node;

        int inIndex = inMap[currVal];

        // IMPORTANT: Build right subtree first for Postorder (Left -> Right -> Root) reverse
        node->right = build(postorder, inIndex + 1, inEnd);
        node->left = build(postorder, inStart, inIndex - 1);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return build(postorder, 0, inorder.size() - 1);
    }
};
