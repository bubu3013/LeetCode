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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        helper(root);
        return res;
}
private:
    void helper(TreeNode *root){
        if (!root)return;
//       initialize the queue
        queue<TreeNode *> q;
//       put the entry point into the queue
        q.push(root);
//       while the queue is not empty
        while (q.empty() == false){
            vector<int> ans;
            int size = q.size();
//       for each node in the queue currently
            for (int i = 0; i < size; i++){
//               poll out 
                TreeNode* cur = q.front(); q.pop();
                ans.push_back(cur->val);
//               expand it
                if (cur->left)q.push(cur->left);
                if (cur->right)q.push(cur->right);
            }
//           level + 1
            res.push_back(ans);
        }
        reverse(res.begin(), res.end());
        return;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Level Order Traversal II.
// Memory Usage: 12.8 MB, less than 17.23% of C++ online submissions for Binary Tree Level Order Traversal II.
