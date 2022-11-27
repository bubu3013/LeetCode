class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root);
    }
private:
    int path = 0;
    int helper(TreeNode* root){
        return max(traverse(root, 0), path);
    }
    int traverse(TreeNode* root, int depth){
        if (root == NULL)return 0;

        int left = traverse(root->left, depth + 1);
        int right = traverse(root->right, depth + 1);
        // path might be the 
        // (1) current max path 
        // (2) the longest path of left-subtree + root + the longest path of right
        path = max(path, left + right);
        // return the longest path of left- or right-subtree 
        // if the root case: no upper path to plus 1
        // else plus 1 for the upper path
        return depth == 0 ? max(left, right) : max(left, right) + 1;
    }
};

// Runtime 19 ms Beats 58.52% 
// Memory 20.2 MB Beats 93.13%
