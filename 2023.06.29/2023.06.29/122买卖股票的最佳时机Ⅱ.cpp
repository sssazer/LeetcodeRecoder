#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(prices.size(), 0)); // dp[0][i]表示今天手上没股票时的最大利润，dp[1][i]表示今天手上有股票时的最大利润
        dp[0][0] = 0, dp[1][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i]); // 有股票时才能卖
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] - prices[i]); // 没股票时才能买
        }
        return max(dp[0][prices.size() - 1], dp[1][prices.size() - 1]);
    }
};

int main() {

	return 0;
}