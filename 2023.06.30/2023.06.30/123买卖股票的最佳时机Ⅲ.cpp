#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[0][i] 表示第i天第一次持有股票时最大利润
        // dp[1][i] 表示第i天第一次未持有股票时的最大利润
        // dp[2][i] 表示第i天第二次持有股票时的最大利润
        // dp[3][i] 表示第i天第二次未持有股票时的最大利润
        vector<vector<int>> dp(4, vector<int>(prices.size(), 0));
        dp[0][0] = -prices[0], dp[1][0] = 0, dp[2][0] = -prices[0], dp[3][0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp[0][i] = max(dp[0][i - 1], -prices[i]); // 第一次持有，要么是之前买的，要么是今天买
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + prices[i]); // 第一次未持有，要么是之前卖的，要么是今天卖的
            dp[2][i] = max(dp[2][i - 1], dp[1][i - 1] - prices[i]); // 第二次持有，要么是之前买的，要么是今天买的
            dp[3][i] = max(dp[3][i - 1], dp[2][i - 1] + prices[i]); // 第二次未持有，要么是之前卖的，要么是今天卖的
        }
        int res = 0;
        for (int i = 0; i < 4; i++) {
            res = max(res, dp[i][prices.size() - 1]);
        }
        return res;
    }
};

//int main() {
//
//    vector<int> prices = {3,3,5,0,0,3,1,4};
//    Solution s;
//    s.maxProfit(prices);
//
//	return 0;
//}