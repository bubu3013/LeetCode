class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        return helper(mat);
    }
private:
    vector<vector<int>> helper(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        // queue for BSF
        queue<pair<int, int>> q;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // up, down, left, right
        // find the multiple resources
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (mat[i][j] == 0){
                    dist[i][j] = 0;
                    q.push(pair<int, int>(i, j)); 
                }
            }
        }
        // BFS
        while (q.empty() == false){
            int r = q.front().first; 
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < dir.size(); i++){ // see the 4 directions
                int new_r = r + dir[i][0];
                int new_c = c + dir[i][1];
                if ((0 <= new_r && new_r < m) && (0 <= new_c && new_c < n)){ // check the boundary
                    if (dist[new_r][new_c] > dist[r][c] + 1){ // if the current min path is bigger
                        dist[new_r][new_c] = dist[r][c] + 1;
                        q.push(pair<int, int>(new_r, new_c));
                    }
                }
            }
        }
        return dist;
    }
};

// Runtime 122 ms Beats 75.39% 
// Memory 30.4 MB Beats 49.45%
