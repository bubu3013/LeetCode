class Solution {
public:
    double average(vector<int>& salary) {
//       notice the type
        double sum = 0.0;
        int n = salary.size();
        int small = salary[0];
        int big = salary[0];
//         find the biggest and the smallest
        for (int i = 0; i < n; i++){
            if (salary[i] < small){small = salary[i];}
            if (salary[i] > big){big = salary[i];}
            sum += (double)salary[i];
        }
        return (sum - small - big) / double(n - 2);
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Average Salary Excluding the Minimum and Maximum Salary.
// Memory Usage: 7.2 MB, less than 42.70% of C++ online submissions for Average Salary Excluding the Minimum and Maximum Salary.
