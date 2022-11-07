class Solution {
public:
    int mySqrt(int x) {
        if (x == 1)return 1;
        return helper(x);
    }
private:
    int helper(int n){
        long long int ans = 0;
        long long int left = 0;
        long long int right = n/2;

        while (left <= right){
            long long int mid = (right - left)/2 + left;
            long long int sqrt_1 = mid * mid;
            long long int sqrt_2 = (mid + 1) * (mid + 1); 
            if (sqrt_1 == n || (sqrt_1 < n && n < sqrt_2)){
                ans = mid;
                break;
            }
            else if (sqrt_1 > n){
                right = mid - 1;
            }
            else if (sqrt_1 < n){
                left = mid + 1;
            }
        }
        return ans;
    }
};

// SPEC: long long int > unsigned int

// Runtime 0 ms Beats 100%
// Memory 5.8 MB Beats 73.79%
