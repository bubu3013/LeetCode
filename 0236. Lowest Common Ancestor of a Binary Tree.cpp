// solution 1: DFS
// if a subtree cannot find it, then it will return NULL
// else return a node

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root, p, q);
    }
private:
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q)return root; // if (1) cannot find or (2)root is the p node or the q node 

        TreeNode* left = helper(root->left, p, q); // DFS to find the left subtree
        TreeNode* right = helper(root->right, p, q); // DFS to find the right subtree

        if (left != NULL && right != NULL)return root; // if both left and right subtrees are non-null, root is the LCA
        return left == NULL ? right : left; // else return the non-null one
    }
};

// Runtime 14 ms Beats 96.69% 
// Memory 14.4 MB Beats 25.42%
