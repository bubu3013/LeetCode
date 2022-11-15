class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return path(obstacleGrid, 0, 0, m, n);
    }
private:
    vector<vector<int>> dp;
    int helper(vector<vector<int>>& g, int i, int j, int m, int n){
        if (i >= m || j >=n || g[i][j] == 1){
            return 0;
        }
        else if (i == m - 1 && j == n - 1){
            return 1;
        }
        else if (dp[i][j] != -1){
            return dp[i][j];
        }
        return dp[i][j] = helper(g, i + 1, j, m, n) + helper(g, i, j + 1, m, n);

    }
    int path(vector<vector<int>>& g, int i, int j, int m, int n){
        dp.resize(105, vector<int>(105, -1));
        return helper(g, i, j, m, n);
    }
};

// Runtime 3 ms Beats 90.52%
// Memory 10.3 MB Beats 13.80%
