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
    bool ans = true;
    bool isBalanced(TreeNode* root) {
        helper(root);
        return ans;
    }
private:
    int helper(TreeNode * root){
//      1. base case
        if (root == NULL)return 0;
//      2. request sub-ans from sub-problems
        int left = helper(root->left);
        int right= helper(root->right);
//      3. get the current ans by sub-ans
        if (abs(left - right) > 1)ans = false;  
//      5. return the ans
        return max(left, right) + 1;;
    }
};

// Runtime: 8 ms, faster than 97.48% of C++ online submissions for Balanced Binary Tree.
// Memory Usage: 20.9 MB, less than 54.64% of C++ online submissions for Balanced Binary Tree.
