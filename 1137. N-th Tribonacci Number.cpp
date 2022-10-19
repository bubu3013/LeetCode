class Solution {
public:
    vector <int> t;
    int tri(int n){
        if (t[n] != (-1))return t[n]; 
        return t[n] = tri(n-1) + tri(n-2) + tri(n-3);
    }
    int tribonacci(int n) {
//       early termination
        if (n == 0)return 0;
        else if (n == 1 || n == 2)return 1;
//       recursive case
        else{
            t.resize(n + 1, -1);
            t[0] = 0;
            t[1] = 1;
            t[2] = 1;
            return tri(n);   
        }
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for N-th Tribonacci Number.
// Memory Usage: 6.2 MB, less than 5.39% of C++ online submissions for N-th Tribonacci Number.
