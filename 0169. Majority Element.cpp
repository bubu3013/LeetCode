// solution 1:

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return helper(nums, nums.size());
    }
private:
    unordered_map <int, int> m;
    int helper(vector<int>& nums, int n){
        int major = floor(n / 2);
        int idx = -1;
        for (auto& x: nums){
            m[x] += 1;
            if (m[x] > major){
                idx = x;
                break;
            }
        }
        return idx;
    }
};

// Runtime 15 ms Beats 98.8% 
// Memory 19.7 MB Beats 14.88%

// time complexity: O(n)
// space complexity: O(n)

// solution 2: Boyer-Moore Voting Algorithm

// ?????

// time complexity: O(n)
// space complexity: O(1)
