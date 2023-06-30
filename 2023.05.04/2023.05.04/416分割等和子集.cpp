#include<iostream>
#include<vector>

using namespace std;

class Solution1 { // 回溯，超时
public:
    bool traceback(vector<int>& nums, int startIndex, int sum1, int sum2) {
        if (sum1 == sum2) {
            return true;
        }
        if (startIndex >= nums.size()) return false;
        if (traceback(nums, startIndex + 1, sum1, sum2)) return true;
        if (traceback(nums, startIndex + 1, sum1 + nums[startIndex], sum2 - nums[startIndex]))
            return true;
        return false;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int& i : nums) {
            sum += i;
        }
        return traceback(nums, 0, 0, sum);
    }
};

class Solution { // 0-1背包，即能否刚好将容量为sum/2的背包装满。也就是尽可能多装，最后再判断能不能装满即可
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int& i : nums) {
            sum += i;
        }
        if (sum % 2 == 1) {
            return false;
        }
        // dp[i][j] 表示在nums[0]~nums[i]中任选数字往容量为j的背包里装，最多能装多少
        vector<vector<int>> dp(nums.size(), vector<int>(sum / 2 + 1, 0));
        for (int i = 1; i <= sum / 2; i++) { // 初始化dp数组第一行
            dp[0][i] = i >= nums[0];
        }
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 1; j <= sum / 2; j++) {
                int choose = 0;
                if (j >= nums[i]) {
                    choose = dp[i - 1][j - nums[i]] + nums[i]; // 如果把第i个数字装进背包里
                }
                int notChoose = dp[i - 1][j]; // 如果不把第i个数字装进背包里
                dp[i][j] = max(choose, notChoose);
            }
        }
        return dp[nums.size() - 1][sum / 2] == (sum / 2);
    }
};

int main() {

    Solution s;
    vector<int> nums = {1,5,11,5};
    s.canPartition(nums);

	return 0;
}