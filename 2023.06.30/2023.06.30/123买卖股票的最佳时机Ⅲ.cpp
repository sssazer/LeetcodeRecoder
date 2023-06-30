#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[0][i] ��ʾ��i���һ�γ��й�Ʊʱ�������
        // dp[1][i] ��ʾ��i���һ��δ���й�Ʊʱ���������
        // dp[2][i] ��ʾ��i��ڶ��γ��й�Ʊʱ���������
        // dp[3][i] ��ʾ��i��ڶ���δ���й�Ʊʱ���������
        vector<vector<int>> dp(4, vector<int>(prices.size(), 0));
        dp[0][0] = -prices[0], dp[1][0] = 0, dp[2][0] = -prices[0], dp[3][0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp[0][i] = max(dp[0][i - 1], -prices[i]); // ��һ�γ��У�Ҫô��֮ǰ��ģ�Ҫô�ǽ�����
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + prices[i]); // ��һ��δ���У�Ҫô��֮ǰ���ģ�Ҫô�ǽ�������
            dp[2][i] = max(dp[2][i - 1], dp[1][i - 1] - prices[i]); // �ڶ��γ��У�Ҫô��֮ǰ��ģ�Ҫô�ǽ������
            dp[3][i] = max(dp[3][i - 1], dp[2][i - 1] + prices[i]); // �ڶ���δ���У�Ҫô��֮ǰ���ģ�Ҫô�ǽ�������
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