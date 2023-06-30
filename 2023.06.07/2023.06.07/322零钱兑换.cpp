#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // ����coins[i] >= 1 && amount <= 10000�����Գ�ʼ��Ϊ10001����Ӱ����Сֵ���ж�
        vector<int> dp(amount + 1, 10001); // װ������Ϊj�ı�����Ҫ������Ӳ����
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        if (dp[amount] == 10001) { // ���û��װ�������������ﻹ�ǳ�ʼֵ
            return -1;
        }
        return dp[amount];
    }
};

int main() {

	return 0;
}