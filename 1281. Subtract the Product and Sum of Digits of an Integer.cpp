class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        while (n){
//           use mod 10 to get the last digit
            product = product * (n % 10);
            sum = sum + (n % 10);
//           iteration
            n /= 10;
        }
        return product - sum;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Subtract the Product and Sum of Digits of an Integer.
// Memory Usage: 5.9 MB, less than 71.31% of C++ online submissions for Subtract the Product and Sum of Digits of an Integer.
