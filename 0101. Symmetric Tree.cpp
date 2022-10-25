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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)return true;
        return helper(root, root);
    }
private:
//   main idea: the left subtree equals to the right subtree
    bool helper(TreeNode *left, TreeNode * right){
        if (left == NULL && right == NULL)return true;
        if (left == NULL || right == NULL)return false; //exclude the both null case
        
        if (left->val != right->val)return false;
        
        return helper(left->left, right->right) && helper(left->right, right->left);
    }
};

// Runtime: 4 ms, faster than 87.86% of C++ online submissions for Symmetric Tree.
// Memory Usage: 16.5 MB, less than 47.32% of C++ online submissions for Symmetric Tree.
