// solution 1: C++
class Solution {
public:
    bool ans = true;
    bool isBalanced(TreeNode* root) {
        helper(root);
        return ans;
    }
private:
    int helper(TreeNode * root){
//      1. base case
        if (root == NULL)return 0;
//      2. request sub-ans from sub-problems
        int left = helper(root->left);
        int right= helper(root->right);
//      3. get the current ans by sub-ans
        if (abs(left - right) > 1)ans = false;  
//      5. return the ans
        return max(left, right) + 1;;
    }
};

// Runtime: 8 ms, faster than 97.48% of C++ online submissions for Balanced Binary Tree.
// Memory Usage: 20.9 MB, less than 54.64% of C++ online submissions for Balanced Binary Tree.


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL)return true;
        return helper(root); 
    }
private:
    bool is_balanced = true;
    bool helper(TreeNode* root){
        traverse(root, 0);
        return is_balanced;
    }
    int traverse(TreeNode* root, int cur){ // to find the largest depth
        if (root == NULL)return cur;

        int left = traverse(root->left, cur + 1);
        int right = traverse(root->right, cur + 1);

        if (abs(left - right) > 1){
            is_balanced = false;
        }

        return max(left, right);
    }
};

// Runtime 25 ms Beats 55.74% 
// Memory 21 MB Beats 27.9%
