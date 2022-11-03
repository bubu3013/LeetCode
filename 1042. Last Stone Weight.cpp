class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        return helper(stones);    
    }
private:
    priority_queue<int> pq;
    int helper(vector<int> &stones){
        for (auto &x : stones){
            pq.push(x);
        }
        while (pq.size() > 1){
            int a = pq.top();pq.pop();
            int b = pq.top();pq.pop();
            
            if (a == b){continue;}
            else{
                pq.push(a - b);
            }
        }
//       no pq[0]
        return pq.size() == 1 ? pq.top() : 0;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Last Stone Weight.
// Memory Usage: 7.7 MB, less than 31.57% of C++ online submissions for Last Stone Weight.
