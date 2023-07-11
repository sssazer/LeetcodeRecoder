#include<iostream>
#include<vector>

using namespace std;

// 同122.买卖股票的最佳时机Ⅱ，只不过相当于我们开局手里就有一个成本为0元的股票

class Solution { // 贪心
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long sum = nums[0];
        int flag = 0; // flag=0表示当前找的是偶数位置，flag=1表示当前找奇数位置
        for (int i = 1; i < nums.size(); i++) {
            if (flag == 0) { // 寻找偶数位置
                if (nums[i] >= nums[i - 1]) { // 偶数位置越大越好
                    sum += nums[i] - nums[i - 1];
                }
                else { // 当碰见变小的时候，就开始寻找奇数位置
                    sum -= nums[i];
                    flag = 1;
                }
            }
            else { // 寻找奇数位置
                if (nums[i] <= nums[i - 1]) { // 奇数位置越小越好
                    sum += nums[i - 1] - nums[i];
                }
                else { // 当碰见变大的时候就开始寻找偶数位置
                    sum += nums[i];
                    flag = 0;
                }
            }
        }
        if (flag == 1) {
            sum += nums[nums.size() - 1];
        }
        return sum;
    }
};


class Solution { // 动态规划
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // dp[i][0]表示选择nums[i]为偶数下标元素时的最大子序列交替和
        // dp[i][1]表示选择nums[i]为奇数下表元素时的最大子序列交替和
        vector<vector<long long>> dp(2, vector<long long>(nums.size(), 0));
        dp[0][0] = nums[0], dp[1][0] = 0;
        for (int i = 1; i < nums.size(); i++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + nums[i]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] - nums[i]);
        }
        return max(dp[0][nums.size() - 1], dp[1][nums.size() - 1]);

    }
};

int main() {

	return 0;
}