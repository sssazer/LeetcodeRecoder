#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[0][i] 表示在第i天持有股票时的最大利润
        // dp[1][i] 表示在第i天未持有股票且未在冷冻期时(第二天能买)的最大利润
        // dp[2][i] 表示在第i天未持有股票且处于冷冻期（第二天不能买）的最大利润
        vector<vector<int>> dp(3, vector<int>(prices.size(), 0));
        dp[0][0] = -prices[0], dp[1][0] = dp[2][0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] - prices[i]);
            if (i > 1) {
                dp[0][i] = max(dp[0][i], dp[2][i - 2] - prices[i]);
            }
            dp[1][i] = max(dp[2][i - 1], dp[1][i - 1]); // 如果今天不在冷冻期，肯定今天不能卖股票
            dp[2][i] = dp[0][i - 1] + prices[i]; // 如果今天持有股票且处于冷冻期，那只能是今天刚卖
        }
        return max(max(dp[0][prices.size() - 1],dp[1][prices.size() - 1]),dp[2][prices.size() - 1]);
    }
};

int main() {

	return 0;
}
