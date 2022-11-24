class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.length() > magazine.length())return false;
        return helper(ransomNote, magazine);
    }
private:
    bool helper(string& note, string& magazine){
        unordered_map<char, int> m;
        bool can_construct = true;
        for (auto& x: magazine){
            m[x]++;
        }
        for (auto& x: note){
            if (m.find(x) == m.end()){ //cannot find the element
                can_construct = false;
                break;
            }else if (m[x] <= 0){ // already run out of the element
                can_construct = false;
                break;
            }else { // can find the element and use once
                m[x]--;
            }
        }
        return can_construct;
    }
};

// Runtime 65 ms Beats 17.52% 
// Memory 8.8 MB Beats 41.4%
