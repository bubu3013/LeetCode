class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1)return intervals;
        return helper(intervals);
    }
private:
    vector<vector<int>> helper(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        vector<int> cur = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (cur[1] < intervals[i][0]) { // no overlapping
                res.push_back(cur);
                cur = intervals[i];
            }else { // overlap -> merge
                cur[0] = min(cur[0], intervals[i][0]); // can omit cuz it is in ascending order
                cur[1] = max(cur[1], intervals[i][1]);
            }
        }
        res.push_back(cur);
        return res;
    }
};

// Runtime 58 ms Beats 74.27% 
// Memory 19 MB Beats 70.40%
