class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        bool valid = false;
        int min_dist = 10000;
        int ans = -1;
        for (int i = 0; i < points.size(); i++){
//             check if valid
            if (points[i][0] == x || points[i][1] == y){
                valid = true;
            }
// if valid, then check whether it is the min distance 
            if (valid){
                int cur = abs(points[i][0] - x) + abs(points[i][1] - y);
                if (min_dist > cur){
                    min_dist = cur;
                    ans = i;
                }
            }
            valid = false;
        }
        return ans;
    }
};

// Runtime: 199 ms, faster than 82.31% of C++ online submissions for Find Nearest Point That Has the Same X or Y Coordinate.
// Memory Usage: 59.5 MB, less than 31.71% of C++ online submissions for Find Nearest Point That Has the Same X or Y Coordinate.
