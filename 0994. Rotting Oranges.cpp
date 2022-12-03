class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        return helper(grid);
    }
private:
    int helper(vector<vector<int>>& g) {
        queue<pair<int, int>> q;
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

        int m = g.size();
        int n = g[0].size();
        int fresh = 0;
        int times = 0;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (g[i][j] == 1)fresh++; // fresh orange
                else if (g[i][j] == 2)q.push(pair<int,int>(i, j)); // rotten orange
            }
        }
        while (fresh > 0 && q.empty() == false){ // when (1) fresh oranges are available (2) new rotten oranges can make others rotten 
            int size = q.size(); 
            for (int i = 0; i < size; i++){ // this round of BFS
                int r = q.front().first; // get an orange
                int c = q.front().second;
                q.pop();
                for (int j = 0; j < dir.size(); j++){ // rotting in 4 directions
                    int new_r = r + dir[j][0];
                    int new_c = c + dir[j][1];
                    if (0 <= new_r && new_r < m && 0 <= new_c && new_c < n && g[new_r][new_c] == 1){
                        g[new_r][new_c] = 2; // mark as rotten
                        fresh--; // with one less fresh orange
                        q.push(pair<int,int>(new_r, new_c)); // new rotten comes in
                    }
                }
            }
            times++; // the end of this round of BFS
        }
        return fresh == 0 ? times : -1; // if we got zero oranges, then return the times of rounds. Else, return -1
    }
};

// Runtime 10 ms Beats 74.54% 
// Memory 13.3 MB Beats 38.4%
