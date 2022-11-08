class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 1 && n == 1)return matrix[0][0] == target;
        if (target < matrix[0][0] || target > matrix[m - 1][n - 1])return false;
        int row = searchRow(matrix, target);
        if (row == -1)return false;
        else return searchCol(matrix[row], target);
    }
private:
    int searchRow(vector<vector<int>>& m, int target){
        if (m.size() == 1)return 0;
        int row = -1;
        int left = 0;
        int right = m.size() - 1;
        int n = m[0].size() - 1;

        while (left <= right){
            int mid = left + (right - left) / 2;
            //to check if the target is in a range !!!
            if (m[mid][0] <= target && target <=  m[mid][n]){
                row = mid;
                break;
            }
            else if (m[mid][0] < target){
                left = mid + 1;
            }
            else if (m[mid][0] > target){
                right = mid - 1;
            }
        }
        return row;
    }
    bool searchCol(vector<int>& v, int target){
        bool ans = false;
        int left = 0;
        int right = v.size() - 1;
        
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (v[mid] == target){
                ans = true;
                break;
            }
            else if (v[mid] < target){
                left = mid + 1;
            }
            else if (v[mid] > target){
                right = mid - 1;
            }
        }
        return ans;
    }
};

// Runtime 7 ms Beats 70.11%
// Memory 9.6 MB Beats 5.6%
