#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        if (sum < abs(target)) {
            return 0;
        }
        if ((sum + target) % 2) {
            return 0;
        }
        int capacity = (sum + target) / 2;
        vector<int> dp(capacity + 1, 0); // dp[j]表示装满容量为j的背包有dp[j]中方法
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = capacity; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[capacity];
    }
};

//int main() {
//
//    Solution s;
//    vector<int> nums = { 1 };
//    s.findTargetSumWays(nums, -1);
//
//	return 0;
//}