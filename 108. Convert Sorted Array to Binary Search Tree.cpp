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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int mid = nums.size() / 2;
        return helper(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* helper(vector<int>& nums, int left, int right){
        if (right - left < 0)return NULL;
        int mid = (left + right) / 2;

        TreeNode * root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid - 1);
        root->right= helper(nums, mid + 1, right);

        return root;
    }
};

// Runtime 22 ms Beats 67.88%
// Memory 21.4 MB Beats 39.74%
