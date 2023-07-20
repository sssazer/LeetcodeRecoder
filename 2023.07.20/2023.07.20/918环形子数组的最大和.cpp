#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) { // 贪心
        // 有两种情况：
        // 1：最长子数组在数组中间，没有跨越头和尾，这种情况直接求最长子数组就可以了
        // 2：最长子数组跨越了头尾，这种情况相当于数组总和减去了中间的最短子数组，求最短子数组就可以了
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int curSumMax = 0, curSumMin = 0;
        int flag = 0, maxNum = 0; // flag用于记录数组是否全是负数，如果全是负数，就返回最大的元素
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                flag = 1;
            }
            maxNum = max(maxNum, nums[i]);
            curSumMax += nums[i];
            curSumMin += nums[i];
            maxSum = max(maxSum, curSumMax);
            minSum = min(minSum, curSumMin);
            if (curSumMax < 0) { // 如果当前子数组和为负数，则重新选择子数组
                curSumMax = 0;
            }
            if (curSumMin > 0) {
                curSumMin = 0;
            }
        }
        if (!flag) {
            return maxNum;
        }
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        return max(maxSum, minSum);
    }
};

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) { // 动态规划
        // 有两种情况：
        // 1：最长子数组在数组中间，没有跨越头和尾，这种情况直接求最长子数组就可以了
        // 2：最长子数组跨越了头尾，这种情况相当于数组总和减去了中间的最短子数组，求最短子数组就可以了
        // 思路和上面相同，只是求最长、最短子数组的方式变为动态规划
        int maxSum = 0, minSum = 0;
        vector<int> maxDp(nums.size(), 0); // dp[i]：以nums[i]为结尾的最大子数组和
        vector<int> minDp(nums.size(), 0); // dp[i]: 以nums[i]为结尾的最小子数组和
        maxDp[0] = minDp[0] = nums[0];
        int flag = 1, maxNum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                flag = 0;
            }
            else {
                maxNum = max(maxNum, nums[i]);
            }
            maxDp[i] = max(maxDp[i - 1] + nums[i], nums[i]);
            minDp[i] = min(minDp[i - 1] + nums[i], nums[i]);
            maxSum = max(maxSum, maxDp[i]);
            minSum = min(minSum, minDp[i]);
        }
        if (flag) {
            return maxNum;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return max(maxSum, sum - minSum);
    }
};
int main() {

	return 0;
}