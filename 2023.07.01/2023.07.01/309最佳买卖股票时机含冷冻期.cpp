#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[0][i] ��ʾ�ڵ�i����й�Ʊʱ���������
        // dp[1][i] ��ʾ�ڵ�i��δ���й�Ʊ��δ���䶳��ʱ(�ڶ�������)���������
        // dp[2][i] ��ʾ�ڵ�i��δ���й�Ʊ�Ҵ����䶳�ڣ��ڶ��첻���򣩵��������
        vector<vector<int>> dp(3, vector<int>(prices.size(), 0));
        dp[0][0] = -prices[0], dp[1][0] = dp[2][0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] - prices[i]);
            if (i > 1) {
                dp[0][i] = max(dp[0][i], dp[2][i - 2] - prices[i]);
            }
            dp[1][i] = max(dp[2][i - 1], dp[1][i - 1]); // ������첻���䶳�ڣ��϶����첻������Ʊ
            dp[2][i] = dp[0][i - 1] + prices[i]; // ���������й�Ʊ�Ҵ����䶳�ڣ���ֻ���ǽ������
        }
        return max(max(dp[0][prices.size() - 1],dp[1][prices.size() - 1]),dp[2][prices.size() - 1]);
    }
};

int main() {

	return 0;
}
