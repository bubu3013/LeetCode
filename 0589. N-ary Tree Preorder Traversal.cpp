/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;
    vector<int> preorder(Node* root) {
        traverse(root);
        return ans;
    }
private:
    void traverse(Node *root){
        if (!root)return;
        
        ans.push_back(root->val);
        for (int i = 0; i < root->children.size(); i++){
            traverse(root->children[i]);
        }
        return;
    }
};
// Runtime: 16 ms, faster than 99.27% of C++ online submissions for N-ary Tree Preorder Traversal.
// Memory Usage: 11.3 MB, less than 26.99% of C++ online submissions for N-ary Tree Preorder Traversal.
