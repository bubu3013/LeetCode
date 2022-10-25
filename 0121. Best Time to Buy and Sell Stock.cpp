using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1)return 0;
        int pri_min = prices[0];
        
        int pro_max = 0;
        
        for (int i = 1; i < prices.size(); i++){
//           the min price from day 0 to day i
            pri_min = min(pri_min, prices[i]);
//           the max profit from day 0 to day i
            pro_max = max(pro_max, prices[i] - pri_min);
        }
        return pro_max;
    }
};

// Runtime: 150 ms, faster than 87.80% of C++ online submissions for Best Time to Buy and Sell Stock.
// Memory Usage: 93.3 MB, less than 88.93% of C++ online submissions for Best Time to Buy and Sell Stock.
