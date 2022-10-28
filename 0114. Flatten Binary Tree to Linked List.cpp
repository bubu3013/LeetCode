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
    void flatten(TreeNode* root) {
        if (root == NULL)return;
        
//      initialze the stack s
        std::stack<TreeNode *> st;
        st.push(root);
//      when the stack is not empty
        while(st.empty() == false){
//          take the top TreeNode
            TreeNode * cur = st.top();st.pop();
//          push the top's right and left into stack 
            if (cur->right)st.push(cur->right);
            if (cur->left)st.push(cur->left);
//          when there is a node which needs to connect with
            if (st.empty() == false){
                TreeNode * tmp = st.top();
                cur->right = tmp;
            }
            cur->left = NULL;
        }
        return;
    }
};

// Runtime: 11 ms, faster than 59.92% of C++ online submissions for Flatten Binary Tree to Linked List.
// Memory Usage: 12.9 MB, less than 17.09% of C++ online submissions for Flatten Binary Tree to Linked List.
