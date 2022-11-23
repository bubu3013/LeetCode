// solution 1: recursive

class Solution {
public:
    int maxDepth(Node* root) {
        return helper(root, 0);
    }
private:
    int helper(Node* root, int cur){
        if (root == NULL)return cur;

        int max_ = 0;
        for (auto& iter: root->children){
            max_ = max(max_, helper(iter, cur + 1));
        }
        return max_ + 1;
    }
};

// Runtime 19 ms Beats 85.21%
// Memory 10.7 MB Beats 89.23%
  
// solution 2: iterative

class Solution {
public:
    int maxDepth(Node* root) {
        return helper(root);
    }
private:
    int helper(Node* root){
        if (root == NULL)return 0;

        queue<Node*> q;
        int depth = 0;
        q.push(root);

        while(q.empty() == false){
            int size = q.size();
            for (int i = 0; i < size; i++){
                Node* tmp = q.front(); q.pop();
                for (auto& iter: tmp->children){
                    q.push(iter);
                }
            }
            depth++;
        }
        return depth;
    }
};

// Runtime 29 ms Beats 58.76%
// Memory 11 MB Beats 6.88%
