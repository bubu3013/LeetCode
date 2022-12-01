class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() == 0)return true;
        vector<vector<int>> v(numCourses, vector<int>()); // to store the prerequisites
        vector<int> visited(numCourses, 0); // 0: unvisited, 1: visiting, 2: visited
        // buld the map: [map, neighbors]
        for (auto& iter: prerequisites){
            v[iter[1]].push_back(iter[0]);
        }
        // topological sorting
        for (int i = 0; i < numCourses; i++){
            if (dfs(i, v, visited)){
                return false; // if dfs with a cycle(true), then return false for the problem
            }
        }
        return true;
    }
private:
    bool dfs(int i, vector<vector<int>>& v, vector<int>& visited){
        if (visited[i] == 1)return true; // with a cycle
        if (visited[i] == 2)return false;// w/o a cycle

        visited[i] = 1; // mark the node as visiting
        for (auto& iter: v[i]){
            if (dfs(iter, v, visited)){
                return true;
            }
        }
        visited[i] = 2; // mark the node as visited
        return false;
    }
};

// Runtime 30 ms Beats 80.18% 
// Memory 13.9 MB Beats 54.7%
