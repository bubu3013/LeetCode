class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int start = findStart(nums, target);
        ans.push_back(start);
        if (start == -1){
            ans.push_back(-1);
            return ans;
        }
        int end = findEnd(nums, target);
        ans.push_back(end);
        return ans;
    }
private:
    int findStart(vector<int>& nums, int target){
        int start = -1;
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right){
            int mid = left + (right - left) / 2;
            if (nums[mid] == target){
                start = mid;
                right = mid - 1; //to see if one more target
            }
            else if (nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return start;
    }
    int findEnd(vector<int>& nums, int target){
        int end = -1;
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right){
            int mid = left + (right - left) / 2;
            if (nums[mid] == target){
                end = mid;
                left = mid + 1; //to see if one more target
            }
            else if (nums[mid] < target){
                left = mid + 1;
            }
            else if (nums[mid] > target){
                right = mid - 1;
            }
        }
        return end;
    }
};

// Runtime 8 ms Beats 91.75%
// Memory 13.6 MB Beats 64.5%
