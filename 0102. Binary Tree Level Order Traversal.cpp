// solution 1: 
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

// solution 2: 2022/11/27

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        return helper(root);
    }
private:
    vector<vector<int>> helper(TreeNode* root) {
        queue<TreeNode *> q;
        vector<vector<int>> res;

        if (root == NULL)return res;
        q.push(root);

        while (q.empty() == false){
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++){
                TreeNode* tmp = q.front(); q.pop();
                level.push_back(tmp->val);
                if (tmp->left)q.push(tmp->left);
                if (tmp->right)q.push(tmp->right);
            }
            res.push_back(level);
        }
        return res;
    }
};

// Runtime 9 ms Beats 36.5%
// Memory 12.6 MB Beats 62.6%
