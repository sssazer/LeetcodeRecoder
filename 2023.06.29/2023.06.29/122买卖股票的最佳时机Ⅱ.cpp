#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(prices.size(), 0)); // dp[0][i]��ʾ��������û��Ʊʱ���������dp[1][i]��ʾ���������й�Ʊʱ���������
        dp[0][0] = 0, dp[1][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i]); // �й�Ʊʱ������
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] - prices[i]); // û��Ʊʱ������
        }
        return max(dp[0][prices.size() - 1], dp[1][prices.size() - 1]);
    }
};

int main() {

	return 0;
}