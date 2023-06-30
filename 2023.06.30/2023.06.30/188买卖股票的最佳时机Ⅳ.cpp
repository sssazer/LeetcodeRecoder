#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // dp[2j][i] ��ʾ��i���е�j + 1�γ��й�Ʊʱ�������
        // dp[2j+1][i] ��ʾ��i���е�j + 1��δ���й�Ʊʱ���������
        vector<vector<int>> dp(2 * k, vector<int>(prices.size(), 0)); 
        for (int j = 0; j < k; j++) {
            dp[2 * j][0] = -prices[0];
            dp[2 * j + 1][0] = 0;
        }
        for (int i = 1; i < prices.size(); i++) {
            dp[0][i] = max(dp[0][i - 1], -prices[i]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + prices[i]);
            for (int j = 1; j < k; j++) {
                dp[2 * j][i] = max(dp[2 * j][i - 1], dp[2 * (j - 1) + 1][i - 1] - prices[i]); // ���й�Ʊ = max(��һ�γ��й�Ʊ����һ��δ���й�Ʊ���������Ʊ)
                dp[2 * j + 1][i] = max(dp[2 * j + 1][i - 1], dp[2 * j][i - 1] + prices[i]); // δ���й�Ʊ = max(��һ��δ���й�Ʊ�����γ��й�Ʊ���ҽ�������)
            }
        }
        int maxProfit = 0;
        for (int i = 0; i < 2 * k; i++) {
            maxProfit = max(maxProfit, dp[i][prices.size() - 1]);
        }
        return maxProfit;
    }
};

int main() {

    vector<int> prices = { 6,1,3,2,4,7 };
    cout << Solution().maxProfit(2, prices);

	return 0;
}