#include<iostream>
#include<vector>

using namespace std;

class Solution1 { // 贪心
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int curPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > curPrice) {
                maxProfit = max(maxProfit, prices[i] - curPrice);
            }
            else {
                curPrice = prices[i];
            }
        }
        return maxProfit;
    }
};

class Solution { // 动态规划
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(prices.size(), 0)); // dp[i][0] 表示第i天手上没股票时最大利润，dp[i][1]表示第i天手上有股票时的最大利润
        dp[0][0] = 0, dp[1][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i]); // 如果今天手上没股票，有两种情况，第一种是一直没买，第二种是今天刚卖
            dp[1][i] = max(dp[1][i - 1], -prices[i]); // 如果今天手上有股票，可能是之前一直有，也可能是今天刚买
        }
        return max(dp[0][prices.size() - 1], dp[1][prices.size() - 1]);
    }
};

//int main() {
//
//    vector<int> prices = { 7,1,5,3,6,4 };
//    Solution s;
//    s.maxProfit(prices);
//
//	return 0;
//}