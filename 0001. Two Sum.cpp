// solution 1: with STL - map

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
//          value      index
        map <int, vector<int>> m;
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); i++){
            m[nums[i]].push_back(i);
        }
        
        for (int i = 0; i < nums.size(); i++){
            auto iter = m.find(target - nums[i]);
            if (iter != m.end()){
                vector<int> tmp = iter->second;
                if (tmp[0] == i && tmp.size() == 2){
                    ans.push_back(i);
                    ans.push_back(tmp[1]);
                    break;
                }
                else if (tmp[0] == i && tmp.size() == 1){
                    continue;
                }
                else{
                    ans.push_back(i);
                    ans.push_back(tmp[0]); 
                    break;
                }
            }
        }
        return ans;
    }
};

// Runtime: 26 ms, faster than 67.41% of C++ online submissions for Two Sum.
// Memory Usage: 14.9 MB, less than 5.27% of C++ online submissions for Two Sum.
