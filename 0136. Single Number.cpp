class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return helper(nums);
    }
private:
    unordered_map <int, int> pm; //positive map
    unordered_map <int, int> nm; //negative map
    int p_sum = 0;
    int n_sum = 0;
    int number = 0;
    int helper(vector<int>& nums){
        for (int i = 0; i < nums.size(); i++){
            int key = nums[i];
            if (key < 0){
                key = -key;
                nm[key] += 1;
                n_sum += 1;
            }else{
                pm[key] += 1;
                p_sum += 1;
            }
        }
        if (p_sum % 2 == 1){
            for (int i = 0; i < pm.size(); i++){
                if (pm[i] == 1){
                   number = i; 
                   break;
                }
            }
        }
        else {
            for (int i = 0; i < nm.size(); i++){
                if (nm[i] == 1){
                   number = -i; 
                   break;
                }
            }
        }
        return number;
    }
};

// Runtime 37 ms Beats 68.80%
// Memory 22 MB Beats 5.24%
