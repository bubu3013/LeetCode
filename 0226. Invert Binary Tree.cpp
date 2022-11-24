// solution 1: iterative

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        return helper(root);
    }
private:
    TreeNode* helper(TreeNode* root) {
        if (root == NULL)return NULL;
        stack<TreeNode*>st;
        st.push(root);

        // BFS
        while(st.empty() == false){
            int size = st.size();
            // swap subtree
            for (int i = 0; i < size; i++){
                TreeNode* cur = st.top(); st.pop();
                // swap the left subtree and right subtree
                TreeNode* tmp = cur->left;
                cur->left = cur->right;
                cur->right = tmp;
                // for the next iteration
                if (cur->left){st.push(cur->left);}
                if (cur->right){st.push(cur->right);}
            }
        }
        return root; 
    }
};
// Runtime 0 ms Beats 100% 
// Memory 9.9 MB Beats 5.34%

// solution 2: recursion

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
private:
    void helper(TreeNode* root) {
        if (root == NULL)return;
        
        // invert the tree
        TreeNode * tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        // iteration
        if (root->left){
            helper(root->left);
        } 
        if (root->right){
            helper(root->right);
        }

        return ; 
    }
};

// Runtime 0 ms Beats 100% 
// Memory 9.7 MB Beats 79.43%
