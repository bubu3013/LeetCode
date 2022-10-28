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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> tmp;
        helper(root, targetSum, tmp);
        return res;
    }
private:
    void helper(TreeNode * node, int target, vector<int> tmp){
//         base case
        if (node == NULL)return;
        if (node->left == NULL && node->right == NULL){
            if (node->val == target){
                tmp.push_back(node->val);
                res.push_back(tmp);
                tmp.pop_back();
                return;
            }
        }
//         request sub-ans from the subproblems
        tmp.push_back(node->val);
        helper(node->left, target - node->val, tmp);
        helper(node->right, target - node->val, tmp);
        tmp.pop_back();
        return;
    }
};

// Runtime: 26 ms, faster than 35.42% of C++ online submissions for Path Sum II.
// Memory Usage: 38.8 MB, less than 13.90% of C++ online submissions for Path Sum II.
