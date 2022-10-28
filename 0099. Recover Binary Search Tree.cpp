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
    TreeNode * first = NULL;
    TreeNode * second= NULL;
    TreeNode * prev = NULL;
    void recoverTree(TreeNode* root) {
        helper(root);
        swap(first, second);
        return;
    }
private:
//   inorder travevrsal
    void helper(TreeNode * root){
        if (root == NULL)return;
        //left
        if (root->left)helper(root->left);
        //root
        if (first == NULL && (prev == NULL || prev->val > root->val)){
            first = prev;
        }
        if (first != NULL && (prev->val > root->val)){
            second = root;
        }
        prev = root;
        //right
        if (root->right)helper(root->right);
        return;
    }
    void swap(TreeNode * first, TreeNode * second){
        int tmp = first->val;
        first->val = second->val;
        second->val=tmp;
    }
};

// Runtime: 51 ms, faster than 74.48% of C++ online submissions for Recover Binary Search Tree.
// Memory Usage: 57.9 MB, less than 71.29% of C++ online submissions for Recover Binary Search Tree.
