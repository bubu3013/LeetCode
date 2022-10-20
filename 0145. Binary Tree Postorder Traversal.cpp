/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
//         basic case
        if (!root)return ans;
//         recursive case
//         post-order: left -> right -> root
        if (root->left)postorderTraversal(root->left);
        if (root->right)postorderTraversal(root->right);
        ans.push_back(root->val);
        return ans;
    }
};

// Runtime: 3 ms, faster than 62.22% of C++ online submissions for Binary Tree Postorder Traversal.
// Memory Usage: 9.5 MB, less than 10.51% of C++ online submissions for Binary Tree Postorder Traversal.
