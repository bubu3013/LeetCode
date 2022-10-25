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
// BFS
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(Node* root) {
        helper(root); 
        return res;
    }
private:
    void helper(Node *root){
        if (root == NULL) return;
//       initialize the queue
        queue <Node*> q;
//       put entry points into the queue
        q.push(root);
//       while the queue is not empty
        while (q.empty() == false){
            vector<int> level;
            int size = q.size();
//           for each node
            for (int i = 0; i < size; i++){
//               poll out an element
                Node * cur = q.front(); q.pop();
//               push it to the ans
                level.push_back(cur->val);
//               expand it
//               1. to check if the cur has the children node
//               2. iterator is "j", not "i"
                if (cur->children.size() != 0){
                    for (int j = 0; j < cur->children.size(); j++){
//               push the children nodes into queue
                        q.push(cur->children[j]);
                    }
                }   
            }
//           level + 1
            res.push_back(level);
        }
    }
};

// Runtime: 20 ms, faster than 97.20% of C++ online submissions for N-ary Tree Level Order Traversal.
// Memory Usage: 11.7 MB, less than 65.51% of C++ online submissions for N-ary Tree Level Order Traversal.
