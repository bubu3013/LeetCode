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
    int sumNumbers(TreeNode* root) {
        vector<int> vec;
        helper(root, vec);
        int sum = 0;
        for (auto& x: number){
            sum += x;
        }
        return sum;
    }
protected:
    vector<unsigned int> number;
private:
    //what you do in base case
    void helper(TreeNode *root, vector<int>& v){
        if (root->left == NULL && root->right  == NULL){
                v.push_back(root->val);
                reverse(v.begin(), v.end());
                unsigned int n = 0;
                unsigned int base = 1;
                for (int i = 0 ; i < v.size(); i++){
                    n = n + base * v[i];
                    base = base * 10;
                }
                number.push_back(n);
                reverse(v.begin(), v.end());
                v.pop_back();
                return;
            }
        //you should also do on the recursive case
        v.push_back(root->val);
        if (root->left){
            helper(root->left, v);
        }
        if (root->right){
            helper(root->right, v);
        }
        //you should also do on the recursive case
        v.pop_back();
        return;
    }
};

// Runtime 0 ms Beats 100%
// Memory 10.1 MB Beats 5.91%
