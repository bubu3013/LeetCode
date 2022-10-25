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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        helper(root);
        return res;
    }
private:
    void helper(TreeNode * root){
        if (!root)return;
        int counter = 0; // only reverse when counter is odd.
//       initialize the queue
        queue<TreeNode *> q;
//       put the entry node into the queue
        q.push(root);
//         while the queue is not empty
        while (q.empty() == false){
            vector<int> ans;
            int size = q.size();
//           for each node in the queue currently
            for (int i = 0; i < size; i++){
//               poll out 
                TreeNode * cur = q.front(); q.pop();
                ans.push_back(cur->val);
//               expand it in order
                if (cur->left)q.push(cur->left);
                if (cur->right)q.push(cur->right);
            }
//           if the counter is odd, then reverse the ans[]
            if (counter % 2 == 1){
                reverse(ans.begin(), ans.end());
            }
            counter = (counter + 1) % 2;    
            res.push_back(ans);  
        }
        return;
    }
};

// Runtime: 3 ms, faster than 83.57% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
// Memory Usage: 12.1 MB, less than 43.59% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
