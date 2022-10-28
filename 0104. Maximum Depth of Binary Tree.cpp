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

// BFS solution
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return helper(root);
    }
private:
    int level = 0;
    int helper(TreeNode * root){
        if (root == NULL)return 0;
        
        queue<TreeNode *> q;
        q.push(root);
        
        while (q.empty() == false){
            int size = q.size();
            for (int i = 0; i < size; i++){
                TreeNode * cur = q.front();q.pop();
                if (cur->left)q.push(cur->left);
                if (cur->right)q.push(cur->right);
            }
            level += 1;
        }
        return level;
    }
};

// Runtime: 13 ms, faster than 69.54% of C++ online submissions for Maximum Depth of Binary Tree.
// Memory Usage: 19 MB, less than 14.26% of C++ online submissions for Maximum Depth of Binary Tree.

// DFS solution
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
    int maxDepth(TreeNode* root) {
        return helper(root, 0);
    }
private:
    int helper(TreeNode * root, int max_depth){
//         1.base case
        if (root == NULL)return 0;
//         initialize 
        int left = 0;
        int right = 0;
//         2.request answers from sub-problems
        if (root->left){
            left = helper(root->left, max_depth);
        }
        if (root->right){
            right = helper(root->right, max_depth);
        }
//         3.get the current answer from requested answers
        max_depth = (left > right ? left : right) + 1;
//         5.return the answer to the main problem
        return max_depth;
    }
};
// Runtime: 8 ms, faster than 91.41% of C++ online submissions for Maximum Depth of Binary Tree.
// Memory Usage: 18.9 MB, less than 55.48% of C++ online submissions for Maximum Depth of Binary Tree.

// int left = helper(root->left, max_depth) will cause error
// because left is the local var only for if-section
