class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        return helper(s, p, s.length(), p.length());
    }
private:
    unordered_map<char, int> smap;
    unordered_map<char, int> pmap;
    vector<int> ans;
    vector<int> helper(string s, string p, int m, int n){
        if (n > m)return ans;
//         build the map for p
        for (int i = 0; i < n; i++){
            pmap[p[i]] += 1;
        }
//         build the map for s, for first n elements
        for (int i = 0; i < n; i++){
            smap[s[i]] += 1;
        }
        if (pmap == smap){
            ans.push_back(0);
        }
//      sliding window to check, from 1 to m - n,
//      cuz the length of "m - n + 1 to m" is m - (m - n + 1) = n - 1 < n,
//      which is impossible for being an anagram for n
        for (int i = 1; i <= m - n; i++){
            smap[s[i - 1]] -= 1;
          // if the element shows up for zero times, then remove
            if (smap[s[i - 1]] == 0){
                smap.erase(s[i - 1]);
            }
            smap[s[i + n - 1]] += 1;
            if (smap == pmap){
                ans.push_back(i);
            }
        }
        return ans;
    }    
};

// Runtime: 67 ms, faster than 24.81% of C++ online submissions for Find All Anagrams in a String.
// Memory Usage: 13.2 MB, less than 10.85% of C++ online submissions for Find All Anagrams in a String.
