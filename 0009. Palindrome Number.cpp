class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)return false;
        return helper(x);
    }
private:
    int pow(int i){
        unsigned int base = 1;
        while (i){
            base = base * 10;
            i--;
        }
        return base;
    }
    bool helper(int x){
        vector<int> v_1;
        vector<int> v_2;
        unsigned int r = 0;
        int cur = x;

        while (cur){
            v_1.push_back(cur % 10);
            cur /= 10;
        }
        v_2 = v_1;

        reverse(v_2.begin(), v_2.end());
        
        return v_1 == v_2;
    }
};

// Runtime 28 ms Beats 53.1%
// Memory 10.4 MB Beats 5.48%
