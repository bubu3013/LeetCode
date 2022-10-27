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

//solution 1: 
// 1. traverse the BST in order and store the value in a vector.
// 2. return false if numbers in the vector are not in order
class Solution {
public:
    vector<int> order;
    bool isValidBST(TreeNode* root) {
        if (root->left == NULL && root->right == NULL)return true;
        helper(root);
        for (int i = 1; i < order.size(); i++){
            if (order[i] <= order[i - 1])return false;
        }
        return true;
    }
private:
    void helper(TreeNode * root){
        if (root == NULL)return;
        
        if (root->left){
            helper(root->left);
        }
        
        order.push_back(root->val);
        
        if (root->right){
            helper(root->right);
        }
        return;
    }
};

// Runtime: 19 ms, faster than 70.81% of C++ online submissions for Validate Binary Search Tree.
// Memory Usage: 21.8 MB, less than 15.57% of C++ online submissions for Validate Binary Search Tree.
