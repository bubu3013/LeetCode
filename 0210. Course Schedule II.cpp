class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        return helper(numCourses, prerequisites);
    }
private:
    vector<int> res;
    vector<int> visited; // 0: non-visited, 1: visiting, 2: visited
    vector<int> helper(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> v(numCourses, vector<int>()); // [prereq's lesson: lesson]
        // initialize the visited vector
        for (int i = 0; i < numCourses; i++){
            visited.push_back(0);
        }
        // course iter[0], then course iter[1]
        for (auto& iter: prerequisites){
            v[iter[1]].push_back(iter[0]);
        }
        // if with cycle, then reture a null vector
        bool with_cyle = false;
        for (int i = 0; i < numCourses; i++){
            if (dfs(i, v)){
                with_cyle = true;
                break;
            }
        }
        if (with_cyle){
            res.clear();
        }
        reverse(res.begin(), res.end());
        return res; 
    }
    bool dfs(int i, vector<vector<int>>& v){
        if (visited[i] == 1)return true;  // with a cycle
        if (visited[i] == 2)return false; // without a cycle
        
        visited[i] = 1; // mark the node as visiting
        for (auto& iter: v[i]){
            if (dfs(iter, v)){
                return true;
            }
        } 
        visited[i] = 2;
        res.push_back(i);
        return false;
    }
};
// Runtime 43 ms Beats 60.34% 
// Memory 14.3 MB Beats 35.34%
