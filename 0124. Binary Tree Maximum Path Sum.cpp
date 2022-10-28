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
    int max_sum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max_sum;
    }
private:
    int dfs(TreeNode * root){
//      1. base case
        if (root == NULL)return 0;
//      2. request ans from sub-problems
        int left = dfs(root->left);
        int right= dfs(root->right);
//      3. get the current ans for current recursion
        left = max(left, 0);
        right= max(right, 0);
//      4. additional operations
//         the sum of the path of "/\"
        max_sum = max(max_sum, left + right + root->val); 
//      return value to the main problem
//      the greater value between (1) left sub-path (2) right sub-path 
//      # (X) "/\" is not the recursive case cuz it does not follow the definitions
        return max(left + root->val, right + root->val); 
    }
};

// Runtime: 41 ms, faster than 71.34% of C++ online submissions for Binary Tree Maximum Path Sum.
// Memory Usage: 27.7 MB, less than 36.01% of C++ online submissions for Binary Tree Maximum Path Sum.
