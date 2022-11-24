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
        queue<TreeNode *> p_path = helper(root, p); // store the path of p
        swap(ans, empty); // the way to clear a queue
        queue<TreeNode *> q_path = helper(root, q); // store the path of q  
        TreeNode * ans = NULL;
        while (p_path.front() == q_path.front()){ // compare the last equal one
            ans = p_path.front();
            p_path.pop();
            q_path.pop();
        }
        return ans;
    }
private:
    // to traverse the tree by DFS
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

// solution 2: by features of BST, the LCA's value will greater than or equal to one's value and smaller than or equal to the other's value  

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root, p, q);
    }
private:
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode * q){
        // base case
        if (root == NULL)return NULL;

        TreeNode* LCA = NULL;
        if ((root->val >= p->val && root->val <= q->val) || (root->val <= p->val && root->val >= q->val)){ // the feature
            return root;
        }else if (root->val > p->val && root->val > q->val){ 
            // if both values of p and q are smaller, then the common acestor will be in the left subtree
            LCA = helper(root->left, p, q);
        }else {
            // if both values of p and q are greater, then the common acestor will be in the right subtree
            LCA = helper(root->right, p, q);
        }
        return LCA;
    }
};
// Runtime 39 ms Beats 80.94% 
// Memory 23.3 MB Beats 19.52%
