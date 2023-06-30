#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // 将nums数组分为两部分，一部分为plus，另一部分为minus
        // 则有 plus + minus = sum，plus - minus = target，于是plus = （sum+target）/2
        // 即转化为0-1背包问题，用nums中的元素装容量为plus的背包，求能装满背包的方案数
        if (nums.size() == 1) {
            if (nums[0] == 0) {
                return 2;
            }
            return nums[0] == target;
        }
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        int capacity = target + (sum - target) / 2;
        if (capacity % 2 == 1) {
            return 0;
        }
        vector<vector<int>> dp(nums.size(), vector<int>(capacity + 1, 0)); // dp[i][j]表示任选nums[0]~nums[i]装容量为j的背包有几种方案能装满
        // 初始化dp数组
        for (int i = 0; i < nums.size(); i++) {
            dp[i][0] = 1; // 背包容量为0时的数值在 nums[i] = j时能用到
            // 此时 dp[i][j] = dp[i - 1][j] + dp[i - 1][0]，当然要+1而不是+0
        }
        for (int i = 1; i <= capacity; i++) {
            dp[0][i] = nums[0] == i;
        }
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 1; j <= capacity; j++) {
                dp[i][j] += dp[i - 1][j]; // 不装当前nums[i]的方案数
                // 装nums[i]的方案数
                if (j >= nums[i]) {
                    dp[i][j] += dp[i - 1][j - nums[i]];
                }
            }
        }
        return dp[nums.size() - 1][capacity];
    }
};

int main() {

	return 0;
}