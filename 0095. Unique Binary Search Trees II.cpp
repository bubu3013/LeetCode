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
    vector<TreeNode *> generator(int start, int end){
        vector<TreeNode *> list;
//         termination
        if (start > end){
            list.push_back(NULL);
            return list;
        }
//          recursive case
        for (int i = start; i <= end; i++){
            vector<TreeNode *> leftTree = generator(start, i - 1);
            vector<TreeNode *> rightTree= generator(i + 1, end);
            
            for (TreeNode* left : leftTree){
                for (TreeNode* right : rightTree){
                    TreeNode * root = new TreeNode(i);
                    root->left = left;
                    root->right= right;
                    list.push_back(root);
                }
            }
        }
        return list;
    }
    vector<TreeNode *> generateTrees(int n) {
        return generator(1, n);
    }
};

// the below video helps a lot.
// https://www.youtube.com/watch?v=gi_Dfz05T6Q&ab_channel=%E8%B4%BE%E8%80%83%E5%8D%9A

// root: 1, null - 1 - subtree of [2 ~ 10]
// root: 2, subtree of [1] - 2 - subtree of [3 ~ 10]
// root: 3, subtree of [1 ~ 2] - 3 - subtree of [4 ~ 10]
// and so on

// for (i: start to end)
//    leftsubtree = generator(start, i-1)
//    rightsubtree = generator(i+1, end)
//    /* to paste all possible sub-trees */ 
//    for (left: leftsubtree) 
//      for (right: rightsubtree)
//        root->val = i;
//        root->left= left;
//        root->right = right;
//        list.push_back(root)

// terminate when (start > end) 
//    1. list.push_back(null) 
//    2. return

// Runtime: 23 ms, faster than 76.54% of C++ online submissions for Unique Binary Search Trees II.
// Memory Usage: 16.1 MB, less than 57.40% of C++ online submissions for Unique Binary Search Trees II.
