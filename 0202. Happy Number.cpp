class Solution {
public:
    bool isHappy(int n) {
        return helper(n); 
    }
private:
    bool helper(int n){
        if (n < 7 && n != 1)return false;
        int end = 0;
        while (n){
            int tmp = n%10;
            n /= 10;
            end = end + tmp * tmp;
        }
        if (end == 1)return true;
        return helper(end);
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Happy Number.
// Memory Usage: 5.8 MB, less than 84.52% of C++ online submissions for Happy Number.

// the number <= 6 is not happy number
