class Solution {
public:
    bool isAnagram(string s, string t) {
        return helper(s, t);
    }
private:
    bool helper(string& s, string& t){
        unordered_map<char, int> m;

        for (int i = 0; i < s.size(); i++){
            m[s[i]]++;
        }

        for (int i = 0; i < t.size(); i++){
            if (m[t[i]] > 0){
                m[t[i]]--;
            }else {
                return false;
            }
        }

        for (auto& iter: m){
            if (iter.second > 0){
                return false;
            }
        }
        return true;
    }
};

// Runtime 17 ms Beats 67.76% 
// Memory 7.4 MB Beats 13.3%
