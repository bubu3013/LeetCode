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
    bool ans = false;
    bool hasPathSum(TreeNode* root, int targetSum) {
        helper(root, targetSum); 
        return ans;
    }
private:
//     top down recursion
    void helper(TreeNode * root, int target){
//         base case
//         (1) null node
        if (root == NULL)return;
//         (2) leaf node
        if (root->left == NULL && root->right == NULL){
            if (root->val == target){
                ans = true;
                return;
            }
        }
        helper(root->left, target - root->val);
        helper(root->right, target - root->val);
        return;
    }
};

// Runtime: 4 ms, faster than 99.32% of C++ online submissions for Path Sum.
// Memory Usage: 21.3 MB, less than 38.44% of C++ online submissions for Path Sum.
