class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '1'){ //an unknown island
                    find(grid, i, j, m, n);
                    ans = ans + 1;
                }
            }
        }
        return ans;
    }
private:
    void find(vector<vector<char>>& grid, int i, int j, int m, int n){
//         water                  found
        if (grid[i][j] == '0' || grid[i][j] == '2')return;
//         mark the island
        grid[i][j] = '2';

//         up
        if (i - 1 >= 0){
            find(grid, i - 1, j, m, n);
        }
//         down
        if (i + 1 < m){
            find(grid, i + 1, j, m, n);
        }
//         left
        if (j - 1 >= 0){
            find(grid, i, j - 1, m, n);
        }
//         right
        if (j + 1 < n){
            find(grid, i, j + 1, m, n);
        }
        return;
    }
};

// Runtime: 43 ms, faster than 86.46% of C++ online submissions for Number of Islands.
// Memory Usage: 12.2 MB, less than 85.28% of C++ online submissions for Number of Islands.
