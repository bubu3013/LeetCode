class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        bool carry = true;

        for (int i = 0; i < digits.size(); i++){
            if (carry){
                digits[i] += 1;
            }
            if (digits[i] == 10){
                digits[i] = 0;
                carry = true;
            }else if (digits[i] != 10){
                carry = false;
                break;
            }
        }
        if (carry){
            digits.push_back(1);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};

// Runtime 3 ms Beats 69.6%
// Memory 8.8 MB Beats 61.75%
