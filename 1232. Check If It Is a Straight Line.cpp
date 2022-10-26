class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        if (c[0][1] == c[1][1]){ //horizonal case?
            for (int i = 2; i < c.size(); i++){
                if (c[i][1] != c[0][1])return false;
            }
            return true;
        }else if (c[0][0] == c[1][0]){//vertical case?
            for (int i = 2; i < c.size(); i++){
                if (c[i][0] != c[0][0])return false;
            }
            return true;
        }else{
//             other case
            for (int i = 1; i < c.size() - 1; i++){
                float s_1 = float(c[i+1][0] - c[i][0])/float(c[i+1][1]-c[i][1]);
                float s_2 = float(c[i][0] - c[i-1][0])/float(c[i][1]-c[i-1][1]);
                if (s_1 != s_2)return false;
            }
            return true;
        }
        
    }
};

// Runtime: 15 ms, faster than 69.77% of C++ online submissions for Check If It Is a Straight Line.
// Memory Usage: 10.1 MB, less than 41.14% of C++ online submissions for Check If It Is a Straight Line.

// Slope the same

// Special case:
// if (y0 == y1 ) // a horizonal line
//  for (int I = 2 ~ n){
//    if (yN != y0) return false
// 	return true
// else if (x0 == x1) // a vertical line
// 	for (int I: 2 ~ n)
// 		if (xN != x0)return false
// 	return true
// Normal case: 
// for (i = 1; i < n – 1; i++)

//  if (s1 != s2) return false;
//     xi+1 - xi            xi – xi-1  
// s1:----------- ,  s2: --------------- 
//     yi+1 - yi            yi – yi-1
// return true;
