/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root){
        helper(root);
        return root;
    }
private:
    void helper(Node * root){
        if (root == NULL)return;
//         initialize a queue
        queue <Node *> q;
//         put the entry node into the queue
        q.push(root);
        while(q.empty() == false){
            vector<Node *> level;
            int size = q.size();
//         for each node in the queue currently
            for (int i = 0; i < size; i++){
//         poll out an element
                Node * cur = q.front(); q.pop();
                level.push_back(cur);
//         expand it in order
                if (cur->left)q.push(cur->left);
                if (cur->right)q.push(cur->right);
            }
//           level: connect
            for (int i = 1; i < level.size(); i++){
                level[i - 1]->next = level[i];
            }
        }
        return;
    }
};

// Runtime: 13 ms, faster than 92.43% of C++ online submissions for Populating Next Right Pointers in Each Node II.
// Memory Usage: 18 MB, less than 8.52% of C++ online submissions for Populating Next Right Pointers in Each Node II.
