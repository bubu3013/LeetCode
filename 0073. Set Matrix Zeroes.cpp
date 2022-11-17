class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        helper(matrix);
    }
private:
    void helper(vector<vector<int>>& matrix){
        unordered_map<int, bool> row;
        unordered_map<int, bool> col;
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++){
            row[i] = false;
        }
        for (int j = 0; j < n; j++){
            col[j] = false;
        }

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == 0){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        for (int i = 0; i < m; i++){
            if (row[i]){
                for (int j = 0; j < n; j++){
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 0; j < n; j++){
            if (col[j]){
                for (int i = 0; i < m; i++){
                    matrix[i][j] = 0;
                }
            }
        }
        return;
    }
};

// Runtime 32 ms Beats 46.15%
// Memory 13.6 MB Beats 11.90%
