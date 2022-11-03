/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    queue<TreeNode *> ans;
    queue<TreeNode *> empty;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode *> p_path = helper(root, p);
        swap(ans, empty); // the way to clear a queue
        queue<TreeNode *> q_path = helper(root, q);  
        TreeNode * ans = NULL;
        while (p_path.front() == q_path.front()){
            ans = p_path.front();
            p_path.pop();
            q_path.pop();
        }
        return ans;
    }
private:
    queue<TreeNode *> helper(TreeNode* root, TreeNode* target){
        if (root->val == target->val){
            ans.push(root);
            return ans;
        }
        
        ans.push(root);
        if (root->val > target->val){
            helper(root->left, target);
        }
        if (root->val < target->val){
            helper(root->right, target);
        }
        return ans;
    }
};

// Runtime: 59 ms, faster than 59.79% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
// Memory Usage: 23.7 MB, less than 18.32% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
