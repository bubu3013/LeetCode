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
    vector<int> postorder(Node* root) {
        vector<int> ans;
        traverse(ans, root);
        return ans;
    }
private:
    void traverse(vector<int> &ans, Node* root){
        if (!root)return;
        
        for (int i = 0; i < root->children.size(); i++){
            traverse(ans, root->children[i]);
        }
        ans.push_back(root->val);
        return ;
    }
};

// Runtime: 31 ms, faster than 75.12% of C++ online submissions for N-ary Tree Postorder Traversal.
// Memory Usage: 11.2 MB, less than 78.59% of C++ online submissions for N-ary Tree Postorder Traversal.
