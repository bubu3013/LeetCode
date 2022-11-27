class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0){
            intervals.push_back(newInterval);
            return intervals;
        }        
        // if the newInterval is smaller than newIntervals[0][0]
        else if (newInterval[1] < intervals[0][0]){
            reverse(intervals.begin(), intervals.end());
            intervals.push_back(newInterval);
            reverse(intervals.begin(), intervals.end());
            return intervals;
        }
        // if the newInterval[0] is bigger than newIntervals[n - 1][m - 1]
        else if (newInterval[0] > intervals[intervals.size() - 1][intervals[0].size() - 1])
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        return helper(intervals, newInterval);
    }
private:
    vector<vector<int>> helper(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start = -1;
        int end = -1;
        int n = intervals.size();
        vector<vector<int>> res;
        // 1. find the start
        for (int i = 0; i < n; i++) {
            if (intervals[i][1] >= newInterval[0]){
                start = i;
                break;
            }
        }
        // 2. find the end
        for (int i = n - 1; i >= 0; i--){
            if (intervals[i][0] <= newInterval[1]){
                end = i;
                break;
            }
        }
        // 3. build the new intervals
        if (end < start){ // no overlapping
            int i = 0;
            while (res.size() != n + 1){
                if (start == i){
                    res.push_back(newInterval);
                    start = -1;
                }else {
                    res.push_back(intervals[i]);
                    i++; 
                }
                
            }
        }
        else { // with overlapping
            for (int i = 0; i < n; i++){
                if (i < start || i > end){
                    res.push_back(intervals[i]);
                }else {
                    vector<int> new_(2, -1);
                    new_[0] = min(intervals[start][0], newInterval[0]);
                    new_[1] = max(intervals[end][1], newInterval[1]);
                    res.push_back(new_);
                    i = end;
                }
            }
        }
        return res;
    }
};

// Runtime 23 ms Beats 80.56% 
// Memory 17.1 MB Beats 38.20%
