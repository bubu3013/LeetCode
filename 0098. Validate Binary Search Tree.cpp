// solution 0: 
// 1. ckeck if the left-subtree is valid
// 2. check if the right-subtree is valid
// 3. return validation of subtrees of left & right 

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root);    
    }
private:
    stack<TreeNode*> st;
    bool helper(TreeNode* root){
        if (root == NULL)return true;

        // traverse in-order: should be ascending
        bool left = helper(root->left);
        // check if it is ascending
        if (st.empty() == false){ 
            if (st.top()->val >= root->val){
                return false;
            }
        }
        st.push(root);
        
        bool right = helper(root->right);
        return left && right;
    }
};

// Runtime 9 ms Beats 95.57% 
// Memory 22.2 MB Beats 5.21%

//solution 1: 
// 1. traverse the BST in order and store the value in a vector.
// 2. return false if numbers in the vector are not in order
class Solution {
public:
    vector<int> order;
    bool isValidBST(TreeNode* root) {
        if (root->left == NULL && root->right == NULL)return true;
        helper(root);
        for (int i = 1; i < order.size(); i++){
            if (order[i] <= order[i - 1])return false;
        }
        return true;
    }
private:
    void helper(TreeNode * root){
        if (root == NULL)return;
        
        if (root->left){
            helper(root->left);
        }
        
        order.push_back(root->val);
        
        if (root->right){
            helper(root->right);
        }
        return;
    }
};

// Runtime: 19 ms, faster than 70.81% of C++ online submissions for Validate Binary Search Tree.
// Memory Usage: 21.8 MB, less than 15.57% of C++ online submissions for Validate Binary Search Tree.

// solution 2: early termination
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root);
    }
private:
    vector<int> prev;
    bool res = true;
    bool helper(TreeNode* root) {
        traverse(root);
        return res;
    }
    void traverse(TreeNode* root) {
        if (root == NULL)return;

        traverse(root->left);
        int n = prev.size();
        if (n != 0){
            if (prev[n - 1] >= root->val){
                res = false;
                return;
            }
        }
        prev.push_back(root->val);
        traverse(root->right);
        return;
    }
};

// Runtime 6 ms Beats 99.1%     
// Memory 22 MB Beats 8.9%
