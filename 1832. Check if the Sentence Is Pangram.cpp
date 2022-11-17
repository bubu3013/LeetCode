class Solution {
public:
    bool checkIfPangram(string sentence) {
        return helper(sentence);
    }
private:
    bool helper(string sentence){
        vector<bool> pangram(26, false); 
        for (auto x: sentence){
            pangram[x - 'a'] = true;
        }
        for (auto x: pangram){
            if (x == false){
                return false;
            }
        }
        return true;
    }
};

// Runtime 5 ms Beats 52.40%
// Memory 6.5 MB Beats 46.74%
