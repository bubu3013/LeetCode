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
    vector<vector<int>> levelOrder(TreeNode* root) {
        helper(root);
        return res;
    }
private:
    void helper(TreeNode *root){
//         early termination
        if (root == NULL)return;
        queue <TreeNode *> q;
//         put all entry nodes into queue
        q.push(root);
//         while queue is not emptu
        while (q.empty() == false){
            vector<int> ans;
//           the size has to be assigned to fix
            int size = q.size(); //notice
//           for each node in the queue (currently)
            for (int i = 0; i < size; i++){
//               poll out the element
                TreeNode * cur = q.front(); q.pop();
//               add it to the answer
                ans.push_back(cur->val);
//               expand it in order, which is left to right in this question 
                if (cur->left)q.push(cur->left);
                if (cur->right)q.push(cur->right);
            }
//           level = level + 1
            res.push_back(ans);
        }
        return;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Level Order Traversal.
// Memory Usage: 12.7 MB, less than 32.07% of C++ online submissions for Binary Tree Level Order Traversal.
