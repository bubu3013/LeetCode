class Solution {
public:
    void sortColors(vector<int>& nums) {
        return quickSort(nums, 0, nums.size() - 1);
    }
private:
    void swap(int& i, int& j){
        int tmp = i;
        i = j;
        j = tmp;
        return;
    }
    void quickSort(vector<int>& nums, int left, int right){
        // base case
        if (left >= right)return;
        // recursive case
        int i = left;
        int j = right;
        int key = nums[left];
        while (i != j){
            while (i < j && nums[j] >= key){
                j--;
            }
            while (i < j && nums[i] <= key){
                i++;
            }
            if (i < j){
                swap(nums[i], nums[j]);
            }
        }
        nums[left] = nums[i];
        nums[i] = key;
        quickSort(nums, left, i - 1);
        quickSort(nums, i + 1, right);
        return;
    }
};
