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

// solution 2: C++ 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        return helper(nums, target);
    }
private:
    vector<int> helper(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> m;
        vector<int> res;
        //build up the map
        for (int i = 0; i < nums.size(); i++){
            m[nums[i]].push_back(i);   
        }
        for (int i = 0; i < nums.size(); i++){
            int rest = target - nums[i];
            auto iter = m.find(rest);
            if (iter != m.end()){
                //if the rest value is equal to nums[i], which means it can only make it when the size of iter->second is 2
                if (nums[i] == rest && iter->second.size() == 2){
                    res.push_back(i);
                    res.push_back(iter->second[1]); 
                //if the rest value is equal to nums[i] but the size of iter->second is 1 -> fail
                }else if (nums[i] == rest && iter->second.size() == 1){
                    continue;
                }
                else if (nums[i] != rest){
                    res.push_back(i);
                    res.push_back(iter->second[0]);
                }
                break;
            }
        }
        return res;
    }
};

// Runtime 29 ms Beats 61.62%
// Memory 14.2 MB Beats 5.11%
