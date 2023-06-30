#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 由于coins[i] >= 1 && amount <= 10000，所以初始化为10001避免影响最小值的判断
        vector<int> dp(amount + 1, 10001); // 装满容量为j的背包需要的最少硬币数
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        if (dp[amount] == 10001) { // 如果没法装满背包，则这里还是初始值
            return -1;
        }
        return dp[amount];
    }
};

int main() {

	return 0;
}