/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        Node* clone = NULL;
        if (node == NULL){
            clone = NULL;
        }else if (node->neighbors.size() == 0){ // without any neighbors
            clone = new Node(node->val);
        }else {
            clone = helper(node);
        }
        return clone;
    }
private:
    unordered_map<Node*, Node*> m; // <old node, new node>
    Node* helper(Node* cur){
        Node * clone = new Node(cur->val);  // deep copy the node
        m[cur] = clone;                     // update the hashmap
        vector<Node *> clone_nei;
        for (auto& iter: cur->neighbors){   // iterate every neighbor in cur node
            if (m.find(iter) == m.end()){   // if the neighboring node has not been cloned
                Node* tmp = helper(iter);      // dfs() to create the node and push back to its neighbor
                clone_nei.push_back(tmp);
            }else{ // if the node has been cloned
                clone_nei.push_back(m[iter]);// add the corresponding new cloned node to its neighbor 
            }
        }
        clone->neighbors = clone_nei; 
        return clone;
    }
};

// Runtime 11 ms Beats 63.15% 
// Memory 9.2 MB Beats 9.90%
