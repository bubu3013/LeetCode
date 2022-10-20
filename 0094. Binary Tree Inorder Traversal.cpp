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
    vector <int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return ans; //!! notice the return type
//         in-order
//         left -> root -> right
        if (root->left){
            inorderTraversal(root->left);   
        }
        ans.push_back(root->val);
        if (root->right){
            inorderTraversal(root->right);   
        }
        
        return ans;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
// Memory Usage: 9.7 MB, less than 11.31% of C++ online submissions for Binary Tree Inorder Traversal.
