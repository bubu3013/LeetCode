class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        return helper(points, k);
    }
private:
    int get_dist(int x, int y) {
        return x * x + y * y;
    }
    vector<vector<int>> helper(vector<vector<int>>& points, int k) {
        // <dist, index>
        priority_queue<pair<int, int>> pq;
        vector<vector<int>> res;
        // create the max heap
        for (int i = 0; i < points.size(); i++){
            int dist = get_dist(points[i][0], points[i][1]);
            pq.push(pair<int, int>(dist, i));
        }
        // from max to min to store points
        for (int i = 0; i < points.size(); i++) {
            int index = pq.top().second;
            pq.pop();
            res.push_back(points[index]);
        }
        // reverse to make it from min to max
        reverse(res.begin(), res.end());
        auto iter_1 = res.begin();
        auto iter_2 = res.begin() + k;
        // get the k closest points
        vector<vector<int>> ans(iter_1, iter_2);
        return ans;
    }
};

// Runtime 483 ms Beats 55.71% 
// Memory 76.5 MB Beats 29.75%
