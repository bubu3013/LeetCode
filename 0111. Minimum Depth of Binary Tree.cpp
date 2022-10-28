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
    int minDepth(TreeNode* root) {
        return helper(root, 0);   
    }
private:
    int helper(TreeNode * root, int min_depth){
//         base case
        if (root == NULL)return 0;
//       The minimum depth is the number of nodes along the shortest path from the root node down to the nearest "leaf node".
//       A leaf is a node with no children. => Base case
        if (root->left == NULL && root->right == NULL)return 1;
        
//          request answers from sub-problems
//       notice the range of depth is 0 to 10,000
        int left = 10005;
        int right = 10005;
        if (root->left){
            left = helper(root->left, min_depth);
        }
        if (root->right){
            right = helper(root->right, min_depth);
        }
//         find the current answer from requested answers
        min_depth = (left < right ? left : right) + 1;
//         return to the main problem
        return min_depth;
    }
};

// Runtime: 311 ms, faster than 82.54% of C++ online submissions for Minimum Depth of Binary Tree.
// Memory Usage: 144.8 MB, less than 45.17% of C++ online submissions for Minimum Depth of Binary Tree.
