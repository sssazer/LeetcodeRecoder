#include<iostream>
#include<vector>

using namespace std;

class Solution1 { // ̰��
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

class Solution { // ��̬�滮
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(prices.size(), 0)); // dp[i][0] ��ʾ��i������û��Ʊʱ�������dp[i][1]��ʾ��i�������й�Ʊʱ���������
        dp[0][0] = 0, dp[1][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i]); // �����������û��Ʊ���������������һ����һֱû�򣬵ڶ����ǽ������
            dp[1][i] = max(dp[1][i - 1], -prices[i]); // ������������й�Ʊ��������֮ǰһֱ�У�Ҳ�����ǽ������
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