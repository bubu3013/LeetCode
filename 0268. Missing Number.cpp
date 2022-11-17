// solution 1: by total

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        return helper(nums);
    }
private:
    int helper(vector<int>& nums){
        int n = nums.size();
        int sum = 0;
        for (auto x: nums){
            sum += x;
        }
        n = (n * (n + 1))/2;
        return n - sum;
    }
};
// Runtime 42 ms Beats 60.14%
// Memory 18 MB Beats 21.59%

// solution 2: by binary search

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return helper(nums);
    }
private:
    int helper(vector<int>& nums){
        int n = nums.size();
        if (nums[n - 1] != n)return n;
        else if (nums[0] != 0)return 0;

        int mid = 0;
        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;

        while (left <= right){
            mid = (left) + (right - left) / 2;
            // check if missing
            if ((mid + 1 < n) && (nums[mid + 1] - nums[mid] != 1 )){
                ans = nums[mid] + 1;
                break;
            }
            // check if missing
            else if ((mid - 1 >=0) && (nums[mid] - nums[mid - 1] != 1 )){
                ans = nums[mid] - 1;
                break;
            }
            else if (mid < nums[mid]){
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

// Runtime 22 ms Beats 89.92%
// Memory 18 MB Beats 21.59%
